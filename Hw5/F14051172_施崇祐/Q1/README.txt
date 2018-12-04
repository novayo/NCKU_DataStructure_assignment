程式執行流程 :
	* 直接執行執行檔
	* 第一行依序輸入要建立的元素
	* 再來依序輸入被取代值跟取代值

程式架構 : 
	分成二部分
		* re_priority-> 用來找到被取代值並替換成取代值
		* reorder    -> 用來排序好整個maxheap
如何設計功能 :
	/***** 43行 -> re_priority(int arr[], int size, int delete, int replace) *****/
			// arr 是 輸入的tree
			// size 是 tree大小
			// delete 是 被取代值
			// replace 是 取代值
	45 ~ 50行 -> 找到被取代值並替換成取代值
	51 ~ 52行 -> 若有找到被取代值，則進入reorder去排列，若沒有則跳出並顯示No match element...
	  


	/***** 56行 -> void reorder(int arr[], int size) *****/
			// arr 是 輸入的tree
			// size 是 tree大小
	57 ~ 78行 -> node去跟小孩比較大小，若比小孩小則交換，而若node是arr[i]，則小孩是arr[i+i+1]跟arr[i+i+2]