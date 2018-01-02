package test;

public class main {
	
	public static void main(String[] args) { 
		ListNode L1;
		ListNode L2;
		ListNode L3;
		int L1_arr[]={1,2,4};
		int L2_arr[]={1,3,4};
		L1=addNodes(L1_arr);
		L2=addNodes(L2_arr);
		
		visitNodes(L1);
		visitNodes(L2);
		
		L3=mergeTwoLists(L1,L2);
		visitNodes(L3);
	}
	private static void visitNodes(ListNode node)
	{
		ListNode currNode=node;
		System.out.print(currNode.val+"->");
		while(currNode.next!=null)
		{
			currNode=currNode.next;
			System.out.print(currNode.val+"->");
		}
		System.out.println("");
		
	}
	private static ListNode addNodes(int []arr){
		
		if(arr.length==0)
			return null;
		
		ListNode currNode=new ListNode(arr[0]);
		ListNode head=currNode;
		currNode.next=null;
		
		for(int i=1;i<arr.length;i++){
			currNode.next=new ListNode(arr[i]);
			currNode=currNode.next;
		}//end of for
		currNode.next=null;
		return head;
	}
	public static ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode currL1=l1;
        ListNode currL2=l2;
        ListNode L3=null;
        ListNode origin_L3=null;
		int value=0;
		
		if (l1==null && l2==null)
			return null;
		
		L3=new ListNode(0);
		origin_L3=L3;
		
		while(currL1!=null || currL2!=null){
			if(currL2==null){
				value=currL1.val;
				if(currL1.next!=null){
					currL1=currL1.next;
				}else{
					currL1=null;
				}
			}else if(currL1==null){
				value=currL2.val;
				if(currL2.next!=null){
					currL2=currL2.next;
				}else{
					currL2=null;
				}
			}else if(currL1.val<=currL2.val){
				value=currL1.val;
				if(currL1.next!=null){
					currL1=currL1.next;
				}else{
					currL1=null;
				}
			}else{
				value=currL2.val;
				if(currL2.next!=null){
					currL2=currL2.next;
				}else{
					currL2=null;
				}
			}
			L3.val=value;
			
			if(currL1!=null || currL2!=null){
				L3.next=new ListNode(0);
				L3=L3.next;
			}
			
		}//end of while
		return origin_L3;
    }

	
}
 

    

