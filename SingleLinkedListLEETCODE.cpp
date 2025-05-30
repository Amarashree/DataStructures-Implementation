#include<iostream>

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void display(const struct ListNode* node){
    std::cout<<"\nNODE DISPLAY\n";
    while(node != nullptr){
        std::cout<<node->val<<"\t";
        node = node->next;
    }
    std::cout<<std::endl;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        
    ListNode* a = new ListNode;
    ListNode* b = a;

    int carry = 0;
    int val1 = 0;
    int val2 = 0;

    while(l1 != nullptr || l2 != nullptr || carry !=0){
        
        if(l1 == nullptr && l2 == nullptr){
            val1 = 0;
            val2 = 0;
        }
        else if(l1 == nullptr){
            val1 = 0;
            val2 = l2->val;
            l2 = l2->next;
        }
        else if(l2 == nullptr){
            val1 = l1->val;
            val2 = 0;
            l1 = l1->next;
        }
        else{
            val1 = l1->val;
            val2 = l2->val;
            l1 = l1->next;;
            l2 = l2->next;
        }
        
        int calc = (val1 + val2 + carry);

        a->val = calc % 10;
        carry = calc/10;

        if(l1 != nullptr || l2 != nullptr || carry != 0)
            a->next = new ListNode;

        

        a = a->next;

    }
    
    return b;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* res = new ListNode(0,head);
        ListNode* dummy = res;

        for(int i=0;i<n;i++){
            head = head->next;
        }

        while(head != nullptr){
            head = head->next;
            dummy = dummy->next;
        }
        dummy->next = dummy->next->next;
        ListNode* result = res->next;
        delete res;

        return result;
    }

ListNode* reverseList(ListNode* head) {

    ListNode* node = nullptr;

    while(head != nullptr){
        ListNode* temp = head->next;
        head->next = node;
        node = head;
        head = temp;
    }
    return node;

}

ListNode* reverseBetween(ListNode* head, int left, int right) {
if(!head || left == right)
    return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* prev = dummy;

    for(int i=0;i<left-1;i++){
        prev = prev->next;
    }

    ListNode* cur = prev->next;

    for(int i=0;i<(right-left);i++){
        ListNode* temp = cur->next;
        cur->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;
    }

    return dummy->next;

}

ListNode* swapPairs(ListNode* head) {
    if(!head || !head->next) return head;


    ListNode* cur;
    ListNode* dummy2 = new ListNode(0);
    dummy2->next = new ListNode(0);
    dummy2->next->next = new ListNode(0);
    ListNode* dummy1 = dummy2;
    

    while(head != nullptr && head->next != nullptr )
    {
        cur = head->next;
        ListNode* temp = cur->next;
        cur->next = head;
        cur->next->next = temp;
        head = temp;
        dummy2->next->next = cur;
        dummy2 = dummy2->next->next;
        
    }
    return dummy1->next->next;
}

ListNode* rotateRight(ListNode* head, int k) {
    if(head == nullptr || head->next == nullptr || k == 0)
        return head;
        
    ListNode* prev = head;
    
    //calculate mod of k
    for(int i=1;i<=k;i++){
        if(prev->next != nullptr)
            prev = prev->next;
        else{
            k = k % i;
            break;
        }
    }

    prev = head;
    for(int i=1;i<=k;i++)
        prev = prev->next;
        
    ListNode* dummy = head;
    while(prev->next != nullptr){
        prev = prev->next;
        head = head->next;
    }

    if(head->next != nullptr){
        ListNode* temp = head;
        head = head->next;
        temp->next = nullptr;
        prev->next = dummy;

        return head;
    }

    return dummy;
    
}

bool hasCycle(ListNode *head) {
    if(head == nullptr || head->next == nullptr)
        return false;

    ListNode* p1 = head;
    ListNode* p2 = head->next;

    if(!p2->next) return false;

    p2 = p2->next;

    while(p2->next != nullptr && p2->next->next != nullptr){
        p2 = p2->next->next;
        p1 = p1->next;
        if(p1 == p2){
            return true;
        }
    }

    return false;
}



int main(){

    ListNode a6(6);
    ListNode a5(5,&a6);
    ListNode a4(4,&a5);
    ListNode a3(3,&a4);
    ListNode a2(2,&a3);
    ListNode a1(1,&a2);
    ListNode a0(0,&a1);

    // example to detect a cycle
    // ListNode a2(2,&a2);
    // ListNode a1(1,&a2);
    // ListNode a0(0,&a1);


    


    display(&a0);
    ListNode* ans = rotateRight(&a0, 40000000);
    display(ans);

    




    std::cout<<"\n\n\n";
    return 0;

   











    std::cout<<"\n\n\n";
    return 0;
}