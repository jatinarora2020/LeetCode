/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
          string lRetVal = "";
      if(root == NULL)
      {
        lRetVal.append("# ");
        return lRetVal;
      }
      lRetVal.append(to_string(root->val)); //appending values
      if(root->left || root->right)
         lRetVal.append("?"); //mark for internal node
      lRetVal.append(" "); //seperator for node data
      if(root->left || root->right)
      {
       lRetVal.append(serialize(root->left));
       lRetVal.append(serialize(root->right)); 
      }
      return lRetVal;
    }

    TreeNode* deserialize_util(string data, int &idx)
    {
        TreeNode* root = NULL;
        int lValue = 0;
        int lNegative = 1;
        if(data[idx] == '?') idx++;
        if(data[idx] == ' ') idx++;
        if(idx >= data.length() || data[idx] == '#')
        {
          idx++;
          return root;
        }
        while(data[idx] != '?' && data[idx] != ' ')
        {
          lValue *= 10;
          if(data[idx] == '-')
            lNegative = -1;
          else
            lValue += (data[idx] - '0');
          idx++;
        }
      lValue*= lNegative;
      root = new TreeNode(lValue);
      if(data[idx] == '?')
      {
        root->left = deserialize_util(data,idx);
        root->right = deserialize_util(data,idx);
      }
      return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      TreeNode* root = NULL;
      int idx = 0;
      root = deserialize_util(data,idx);
      return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));