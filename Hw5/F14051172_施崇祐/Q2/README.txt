�{������y�{ :
	* �������������
	* �Ĥ@��̧ǿ�J�n�إߪ�����
	* �A�Ө̧ǿ�J�Q�R����

�{���[�c : 
	�����G����
		* mdelete    -> ���Q�R���ȨçR��
		* reorder    -> �ΨӱƧǦn���maxheap
�p��]�p�\�� :
	/***** 56�� -> mdelete(int arr[], int size, int delete) *****/
			// arr �O ��J��tree
			// size �O tree�j�p
			// delete �O�n�R������
	53 ~ 61�� -> ��Q�R���ȸ�̫�@�ӳ̤p���ȥ洫����size--
	     63�� -> �ƧǦn��maxheap
	
	/***** 68�� -> reorder(int arr[], int size, int i) *****/
			// arr �O ��J��tree
			// size �O tree�j�p
			// i �O�n�R�����Ȫ�index
	69 ~ 90�� -> node�h��p�Ĥ���j�p�A�Y��p�Ĥp�h�洫�A�ӭYnode�Oarr[i]�A�h�p�ĬOarr[i+i+1]��arr[i+i+2]