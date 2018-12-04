程式執行流程 :
	* 直接執行執行檔
	* 第一行依序輸入要建立的元素
	* 再來依序輸入被刪除值

程式架構 : 
	分成二部分
		* mdelete    -> 找到被刪除值並刪除
		* reorder    -> 用來排序好整個maxheap
如何設計功能 :
	/***** 56行 -> mdelete(int arr[], int size, int delete) *****/
			// arr 是 輸入的tree
			// size 是 tree大小
			// delete 是要刪除的值
	53 ~ 61行 -> 把被刪除值跟最後一個最小的值交換並讓size--
	     63行 -> 排序好成maxheap
	
	/***** 68行 -> reorder(int arr[], int size, int i) *****/
			// arr 是 輸入的tree
			// size 是 tree大小
			// i 是要刪除的值的index
	69 ~ 90行 -> node去跟小孩比較大小，若比小孩小則交換，而若node是arr[i]，則小孩是arr[i+i+1]跟arr[i+i+2]