class Solution {
   public:
   int numComponents(ListNode* head, vector<int>& G) {
      int ret = 0;
      set < int > s;
      for(int i = 0; i < G.size(); i++)s.insert(G[i]);
      bool flag = false;
      while(head){
         int x = head->val;
         if(s.count(x)){
            if(!flag) ret++;
            flag = true;
         }else flag = false;
         head = head->next;
      }
      return ret;
   }
};
