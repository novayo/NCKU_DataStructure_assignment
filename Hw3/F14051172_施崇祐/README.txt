
程式執行流程 :
	直接執行執行檔

程式架構 : 
	分成三部分
		* struct() -> 定義出Doubly Linked List結構，有data, next, pre
 		* main()   -> 輸入文字、切割輸入文字、輸出結果
		* create() -> 建立新的節點
如何設計功能 :
	Main Idea: 運用雙向linkrd list去實現在兩端分別的Queue
	5  ~  9行 -> 定義節點結構，data是要存的資料，next是指到下一個節點，pre是指到上一個節點
	     11行 -> 宣告create函數
	
	/***** 進入main() *****/
	15 ~ 18行 -> 建立第一個節點，並初始化data = -1
	20 ~ 23行 -> 變數宣告，input放輸入的全部文字，frag_str放輸入文字的文字部分(因為不會超過10格，所以定義成11格，最後一格放'\0')，frag_int放輸入文字的數字部分(初始化成-1)
	25 ~ 46行 -> 擷取輸入文字
	48 ~ 51行 -> 建立新節點或是break
	55 ~ 63行 -> 顯示結果

	/***** 進入create() *****/
	     68行 -> 如果是第一次輸入，則data = input，next跟pre都是NULL
	74 ~ 77行 -> new是新的節點，因此先讓new的data附值，而next跟pre等等定義，因為push pop front back的需求不同
		  -> tmp是暫時節點，使用tmp去執行動作，因此使tmp = node
	78 ~ 83行 -> 定義new的next = NULL(因為是加在最右邊)
		  -> 將tmp移到link list的最右邊的位置，然後再使tmp->next指向new，new->pre指向tmp
	84 ~ 89行 ->定義new的pre= NULL(因為是加在最左邊)
		  -> 將tmp移到link list的最左邊的位置，然後再使tmp->pre指向new，new->next指向tmp
	78 ~ 83行 -> 將tmp移到link list的最右邊的位置，然後再使tmp->next指向new，new->pre指向tmp
		  -> 將tmp前一格的next指到NULL，再將tmp的pre指向NULL，最後free tmp那個位置
	84 ~ 89行 -> 將tmp移到link list的最左邊的位置，然後再使tmp->pre指向new，new->next指向tmp
		  -> 將tmp後一格的pre指到NULL，再將tmp的>next指向NULL，最後free tmp那個位置