/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
const removeNthFromEnd = (head, n) => {
  let length = 0
  let cur = head
  let retVal = head
  let prev = null
  
  // check the length of head
  while (cur !== null) {
    length++
    cur = cur.next
  }
  cur = head
  
  if (length === n) {
    return head.next
  }
    
  // remove appropriate node
  for (let i = 0; i < length; i++) {
    if (i === length - n) {
        prev.next = cur.next
      break
    } else {
      prev = cur
      cur = cur.next
    }
  }
  return retVal
};