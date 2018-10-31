Q1:
<Main.c>
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

Q2-1:
<eval.c>
程式執行流程 :
	* 直接執行執行檔
	* 輸入文字時要每個文字及符號間都要有"空格"     Example: "- / * 10 + 5 3 8 2"
	* 輸入q則跳出並顯示結果

程式架構 : 
	分成二部分
		* 輸入文字，如果是q則跳出
		* 用stack算出答案
如何設計功能 :
	Main Idea: 用ans這個陣列實現stack，並用老師說的看到符號就pop兩個人做計算再push回去，看到數字就stack
	11 ~ 13行 -> 輸入文字，若是輸入q，則跳出
	16 ~ 27行 -> 若看到數字，則做stack
	28 ~ 44行 -> 若看到符號
		31 ~ 32行 -> pop出2個數字
		33 ~ 41行 -> 做計算 
	     46行 -> 輸出結果

Q2-2:
<prefix.c>
程式執行流程 :
	* 直接執行執行檔
	* 輸入文字時要每個文字及符號間都要有"空格"     Example: "- / * 10 + 5 3 8 2"
	* 輸入q則跳出並顯示結果

程式架構 : 
	分成三部分
		* 輸入文字，如果是q則跳出
		* 用stack算出答案
		* 定義出輸出的符號
如何設計功能 :
	Main Idea: 先定義出 +-*/() 的優先權，然後再用老師教的方法去做stack
	20 ~ 23行 -> 輸入文字，若是輸入q，則跳出
	25 ~ 43行 -> 若看到數字，則做stack
	45 ~ 82行 -> 若看到符號
		46 ~ 58行 -> 先定義優先權
		60 ~ 82行 -> 用老師教的方法去做stack
	     	83 ~ 85行 -> 可能會沒pop完，故用此方法讓他pop完
		87 ~ 95行 -> 輸出結果







