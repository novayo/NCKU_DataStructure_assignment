程式執行流程 :
	* 直接執行執行檔
	* 第一行輸入要建立的元素的個數
	* 再來依序輸入邊跟邊跟weight

程式架構 : 
	分成二部分
		* weighFind   -> 找root
		* simpleUnion -> 若a的rank小於b的rank，則將a的root設成b的
			      -> 若b的rank小於a的rank，則將b的root設成b的
			      -> 若b的rank==a的rank，則將b的rank設成a的並把a的rank+1，使其分開
		* Sollin      -> 從0開始找，找他的子項中最小的那個vertex並把他union起來，並在80~88行判斷是否有形成迴路，若有則continue