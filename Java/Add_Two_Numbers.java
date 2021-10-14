/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode rNode = new ListNode(0); 
        ListNode current = rNode;
        int sum = 0;
        int carry = 0;
        while(l1 != null && l2 != null){
            sum = l1.val + l2.val + carry;
            rNode.next = new ListNode(sum % 10);
            rNode = rNode.next;
            carry = sum / 10;
            if(carry != 0){
                rNode.next = new ListNode(carry);
            }
            l1 = l1.next;
            l2 = l2.next;
        }
        if(l1 != null){
            while(l1 != null){
                sum = l1.val + carry;
                rNode.next = new ListNode(sum % 10);
                rNode = rNode.next;
                carry = sum / 10;
                if(carry != 0){
                    rNode.next = new ListNode(carry);
                }
                l1 = l1.next;
            }
        }
        if(l2 != null){
            while(l2 != null){
                sum = l2.val + carry;
                rNode.next = new ListNode(sum % 10);
                rNode = rNode.next;
                carry = sum / 10;
                if(carry != 0){
                    rNode.next = new ListNode(carry);
                }
                l2 = l2.next;
            }
        }
        return current.next;
    }
}
