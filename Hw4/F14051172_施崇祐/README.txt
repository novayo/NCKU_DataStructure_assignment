�{������y�{ :
	* �������������
	* �Ĥ@���J {row�ƥ� col�ƥ� term�ƥ�}�A�C�Ӥ�r�βŸ������n��"�Ů�"
	* �A�ӿ�J {row, col, value}�A�Ÿ������n��"�Ů�"

�{���[�c : 
	����������
		* mmult      -> �Ψӯx�}�ۭ�
		* mread      -> �Ψӿ�J�x�}
		* mtranspose -> �Ψ���ܯx�}
		* mwrite     -> ��ܯx�}
		* merase     -> ����linked list
�p��]�p�\�� :
	/***** mmult(node1, node2, sn, tn1, tn2) -> a * b_transpose *****/
			// node1 �O a
			// node2 �O b_transpose
			// sn    �O �������k����A�n�^�Ǫ�node���N��
			// tn1   �O a���N��
			// tn2   �O b_transpose���N��
	55 ~ 59�� -> �p�G��}�C��������ۭ��A�h�^�ǪŪ�node
	62 ~ 67�� -> �]�w���Y�`�IH
	     69�� -> NumHeads �O H0 ~ Hx ���s���Acol��row����j��
	74 ~ 80�� -> ��l�� H0 ~ Hx
		  -> HdNode[Vars][i] -> Vars�N��Onode�N��(a���ܬO0�Ab�O1...)
	84 ~122�� -> �إ߭��X�Ӫ�linked list
		  	-> 88 ~ 93 �� -> terms�ۭ�(a�Hrow���Ab�Hcol��)
			-> 101~121 �� -> ��ȩ�i�hlinked list(�Hrow��i�h)
	124~134�� -> ����Ы��^�h�ӫ����a��

	  

	/***** 139�� -> mtranspose(sn, tn) -> b to b_transpose *****/
			// sn �O ������ܤ���A�n�^�Ǫ�node���N��
			// tn1   �O b���N��
	144~147�� -> �]�w���Y�`�IH
	    150�� -> NumHeads �O H0 ~ Hx ���s���Acol��row����j��
	154~160�� -> ��l�� H0 ~ Hx
		  -> HdNode[Vars][i] -> Vars�N��Onode�N��(a���ܬO0�Ab�O1...)
	165~192�� -> �إ߭��X�Ӫ�linked list
		  	-> 167~168 �� -> ��ȱqb ���X�ӡA��row��col���(b�Hrow��)
			-> 171~191 �� -> ��ȩ�i�hlinked list(�Hrow��i�h)
	194~204�� -> ����Ы��^�h�ӫ����a��



	/***** 209�� -> mtranspose(sn) -> ��J�x�} *****/
			// sn �O ������ܤ���A�n�^�Ǫ�node���N��
	213~214�� -> �̧ǿ�J�� row col entries���ƥ�
	    215�� -> NumHeads �O H0 ~ Hx ���s���Acol��row����j��
	218~221�� -> �]�w���Y�`�IH
	227~233�� -> ��l�� H0 ~ Hx
		  -> HdNode[Vars][i] -> Vars�N��Onode�N��(a���ܬO0�Ab�O1...)
	235~262�� -> �إ߭��X�Ӫ�linked list
		  	-> 239~240 �� -> ��Jrow, col, value
			-> 242~262 �� -> ��ȩ�i�hlinked list(�Hrow��i�h)
	264~275�� -> ����Ы��^�h�ӫ����a��


	/***** 280�� -> mwrite(node, sn) -> ��ܯx�} *****/
			// node �O �n��ܪ��}�C
			// sn �O ������ܤ���A�n�^�Ǫ�node���N��
	280~293�� -> �̧���ܾ�Ӱ}�C�A�������a���0              <- �[���D



	/***** 295�� -> merase(*node, sn) -> ����linked list *****/
			// node �O �n����linked list
			// sn �O ������ܤ���A�n�^�Ǫ�node���N��
	295~311�� -> �̧�����`�I