程式執行流程 :
	* 直接執行執行檔
	* 第一行輸入 {row數目 col數目 term數目}，每個文字及符號間都要有"空格"
	* 再來輸入 {row, col, value}，符號間都要有"空格"

程式架構 : 
	分成五部分
		* mmult      -> 用來矩陣相乘
		* mread      -> 用來輸入矩陣
		* mtranspose -> 用來轉至矩陣
		* mwrite     -> 顯示矩陣
		* merase     -> 釋放linked list
如何設計功能 :
	/***** mmult(node1, node2, sn, tn1, tn2) -> a * b_transpose *****/
			// node1 是 a
			// node2 是 b_transpose
			// sn    是 做完乘法之後，要回傳的node的代號
			// tn1   是 a的代號
			// tn2   是 b_transpose的代號
	55 ~ 59行 -> 如果兩陣列本身不能相乘，則回傳空的node
	62 ~ 67行 -> 設定標頭節點H
	     69行 -> NumHeads 是 H0 ~ Hx 的編號，col跟row中選大的
	74 ~ 80行 -> 初始化 H0 ~ Hx
		  -> HdNode[Vars][i] -> Vars代表是node代號(a的話是0，b是1...)
	84 ~122行 -> 建立乘出來的linked list
		  	-> 88 ~ 93 行 -> terms相乘(a以row拿，b以col拿)
			-> 101~121 行 -> 把值放進去linked list(以row放進去)
	124~134行 -> 把指標指回去該指的地方

	  

	/***** 139行 -> mtranspose(sn, tn) -> b to b_transpose *****/
			// sn 是 做完轉至之後，要回傳的node的代號
			// tn1   是 b的代號
	144~147行 -> 設定標頭節點H
	    150行 -> NumHeads 是 H0 ~ Hx 的編號，col跟row中選大的
	154~160行 -> 初始化 H0 ~ Hx
		  -> HdNode[Vars][i] -> Vars代表是node代號(a的話是0，b是1...)
	165~192行 -> 建立乘出來的linked list
		  	-> 167~168 行 -> 把值從b 拿出來，把row跟col對調(b以row拿)
			-> 171~191 行 -> 把值放進去linked list(以row放進去)
	194~204行 -> 把指標指回去該指的地方



	/***** 209行 -> mtranspose(sn) -> 輸入矩陣 *****/
			// sn 是 做完轉至之後，要回傳的node的代號
	213~214行 -> 依序輸入值 row col entries的數目
	    215行 -> NumHeads 是 H0 ~ Hx 的編號，col跟row中選大的
	218~221行 -> 設定標頭節點H
	227~233行 -> 初始化 H0 ~ Hx
		  -> HdNode[Vars][i] -> Vars代表是node代號(a的話是0，b是1...)
	235~262行 -> 建立乘出來的linked list
		  	-> 239~240 行 -> 輸入row, col, value
			-> 242~262 行 -> 把值放進去linked list(以row放進去)
	264~275行 -> 把指標指回去該指的地方


	/***** 280行 -> mwrite(node, sn) -> 顯示矩陣 *****/
			// node 是 要顯示的陣列
			// sn 是 做完轉至之後，要回傳的node的代號
	280~293行 -> 依序顯示整個陣列，不足的地方補0              <- 加分題



	/***** 295行 -> merase(*node, sn) -> 釋放linked list *****/
			// node 是 要釋放的linked list
			// sn 是 做完轉至之後，要回傳的node的代號
	295~311行 -> 依序釋放節點