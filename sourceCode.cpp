#include<iostream>
using namespace std;


//Definition for singly-linked list.

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* result;
    ListNode* current;
    //...............CONSTRUCTOR.................
    Solution(){
        result = createNode(0);
        current = result;
    }
    
    //...............FUNCTION TO CREATE A NEW NODE.................
    ListNode* createNode(int x){
        ListNode* m = new ListNode(x);
        return m;
    }
    
    //...............CONVERTING THE INPUT INTEGER INTO LINKED LIST.................
    ListNode* intToLinkedList(int num){
        int temp=num, r;
        ListNode* n = createNode(0);
        ListNode* curr = n;
        
        while(temp!=0){
            r = temp%10;
            curr->val = r;
            temp /= 10;
            ListNode* m = createNode(0);
            curr->next = m;
            curr = curr->next;
        }
        return n;
    }
    
    //...............POWER OF A NUMBER.................
    int power(int x, int y){
        int temp = x;
        for(int i=0; i<y; i++){
            temp *= x;
        }
        return temp;
    }
    
    //...............CONVERTING THE LINKED LIST INTO INTEGER.................
    
    int linkedListToInt(ListNode* list){
        int sum=0, count=0;
        while(list!=NULL){
            sum = sum + power(10, count);
            list = list->next;
	    count++;
        }
        return sum;
    }

    
    //...............ADD TWO NUMBERS.................
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //...............L1 and L2 are NULL.................
        
        if(l1==NULL && l2==NULL) return result;
        
        
        //...............IF L1 is NULL.................
        
        else if(l1==NULL && l2!=NULL){
            if(l2->val > 9){
                int pr, ptemp = l2->val;
                pr = ptemp%10;
                ptemp /= 10;
                current->val = pr;
                
                ListNode* n = createNode(0);
                current->next = n;
                current = current->next;
                
                if(l2->next == NULL){
                    ListNode* t = createNode(ptemp);
                    l2->next = t;
                }
                else{
                    l2->next->val += ptemp;
                }
            }
            else{
                current->val = l2->val;
                if(l2->next!=NULL){
                    ListNode* n = createNode(0);
                    current->next = n;
                    current = current->next;
                }
            }
            return addTwoNumbers(l1, l2->next);
        }
        
        
        //...............IF L2 is NULL.................
        
        else if(l1!=NULL && l2==NULL){
            if(l1->val > 9){
                int pr, ptemp = l1->val;
                pr = ptemp%10;
                ptemp /= 10;
                current->val = pr;
                
                ListNode* n = createNode(0);
                current->next = n;
                current = current->next;
                
                if(l1->next == NULL){
                    ListNode* t = createNode(ptemp);
                    l1->next = t;
                }
                else{
                    l1->next->val += ptemp;
                }
            }
            else{
                current->val = l1->val;
                if(l1->next!=NULL){
                    ListNode* n = createNode(0);
                    current->next = n;
                    current = current->next;
                }
            }
            return addTwoNumbers(l1->next, l2);
        }
        
        
        //...............ELSE.................
        
        int temp, r;
        temp = l1->val + l2->val;
        
        ListNode* n = createNode(0);
        
        if(temp>9){
            r = temp%10;
            temp /= 10;
            current->val = r;
            if(l1->next == NULL){
                ListNode* t = createNode(temp);
                l1->next = t;
            }
            else{
                l1->next->val += temp;
            }
        }
        else{
            current->val = temp;
        }
        
        if(l1->next == NULL && l2->next == NULL) return addTwoNumbers(l1->next, l2->next);
        
        current->next = n;
        current = current->next;
        
        return addTwoNumbers(l1->next, l2->next);
    }
};    
    //...............MAIN FUNCTION (ENTRY POINT).................
    
    int main(){
		Solution s;

		ListNode* sum = s.createNode(0);
        ListNode* l1 = s.createNode(0);
        ListNode* l2 = s.createNode(0);

        int a, b;
		cout<<"Enter A and B : ";
        cin>>a>>b;
        
        l1 = s.intToLinkedList(a);
        l2 = s.intToLinkedList(b);
        
        
        sum = s.addTwoNumbers(l1, l2);
        
        int c = s.linkedListToInt(sum);
        cout<<"A : "<<a<<"\nB : "<<b<<"\n\nSUM : "<<c<<"\n";
        
        return 0;
    }
	
