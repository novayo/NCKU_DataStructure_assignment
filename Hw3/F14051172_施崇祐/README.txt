Q1:
<Main.c>
�{������y�{ :
	�������������

�{���[�c : 
	�����T����
		* struct() -> �w�q�XDoubly Linked List���c�A��data, next, pre
 		* main()   -> ��J��r�B���ο�J��r�B��X���G
		* create() -> �إ߷s���`�I
�p��]�p�\�� :
	Main Idea: �B�����Vlinkrd list�h��{�b��ݤ��O��Queue
	5  ~  9�� -> �w�q�`�I���c�Adata�O�n�s����ơAnext�O����U�@�Ӹ`�I�Apre�O����W�@�Ӹ`�I
	     11�� -> �ŧicreate���
	
	/***** �i�Jmain() *****/
	15 ~ 18�� -> �إ߲Ĥ@�Ӹ`�I�A�ê�l��data = -1
	20 ~ 23�� -> �ܼƫŧi�Ainput���J��������r�Afrag_str���J��r����r����(�]�����|�W�L10��A�ҥH�w�q��11��A�̫�@���'\0')�Afrag_int���J��r���Ʀr����(��l�Ʀ�-1)
	25 ~ 46�� -> �^����J��r
	48 ~ 51�� -> �إ߷s�`�I�άObreak
	55 ~ 63�� -> ��ܵ��G

	/***** �i�Jcreate() *****/
	     68�� -> �p�G�O�Ĥ@����J�A�hdata = input�Anext��pre���ONULL
	74 ~ 77�� -> new�O�s���`�I�A�]������new��data���ȡA��next��pre�����w�q�A�]��push pop front back���ݨD���P
		  -> tmp�O�Ȯɸ`�I�A�ϥ�tmp�h����ʧ@�A�]����tmp = node
	78 ~ 83�� -> �w�qnew��next = NULL(�]���O�[�b�̥k��)
		  -> �Ntmp����link list���̥k�䪺��m�A�M��A��tmp->next���Vnew�Anew->pre���Vtmp
	84 ~ 89�� ->�w�qnew��pre= NULL(�]���O�[�b�̥���)
		  -> �Ntmp����link list���̥��䪺��m�A�M��A��tmp->pre���Vnew�Anew->next���Vtmp
	78 ~ 83�� -> �Ntmp����link list���̥k�䪺��m�A�M��A��tmp->next���Vnew�Anew->pre���Vtmp
		  -> �Ntmp�e�@�檺next����NULL�A�A�Ntmp��pre���VNULL�A�̫�free tmp���Ӧ�m
	84 ~ 89�� -> �Ntmp����link list���̥��䪺��m�A�M��A��tmp->pre���Vnew�Anew->next���Vtmp
		  -> �Ntmp��@�檺pre����NULL�A�A�Ntmp��>next���VNULL�A�̫�free tmp���Ӧ�m

Q2-1:
<eval.c>
�{������y�{ :
	* �������������
	* ��J��r�ɭn�C�Ӥ�r�βŸ������n��"�Ů�"     Example: "- / * 10 + 5 3 8 2"
	* ��Jq�h���X����ܵ��G

�{���[�c : 
	�����G����
		* ��J��r�A�p�G�Oq�h���X
		* ��stack��X����
�p��]�p�\�� :
	Main Idea: ��ans�o�Ӱ}�C��{stack�A�åΦѮv�����ݨ�Ÿ��Npop��ӤH���p��Apush�^�h�A�ݨ�Ʀr�Nstack
	11 ~ 13�� -> ��J��r�A�Y�O��Jq�A�h���X
	16 ~ 27�� -> �Y�ݨ�Ʀr�A�h��stack
	28 ~ 44�� -> �Y�ݨ�Ÿ�
		31 ~ 32�� -> pop�X2�ӼƦr
		33 ~ 41�� -> ���p�� 
	     46�� -> ��X���G

Q2-2:
<prefix.c>
�{������y�{ :
	* �������������
	* ��J��r�ɭn�C�Ӥ�r�βŸ������n��"�Ů�"     Example: "- / * 10 + 5 3 8 2"
	* ��Jq�h���X����ܵ��G

�{���[�c : 
	�����T����
		* ��J��r�A�p�G�Oq�h���X
		* ��stack��X����
		* �w�q�X��X���Ÿ�
�p��]�p�\�� :
	Main Idea: ���w�q�X +-*/() ���u���v�A�M��A�ΦѮv�Ъ���k�h��stack
	20 ~ 23�� -> ��J��r�A�Y�O��Jq�A�h���X
	25 ~ 43�� -> �Y�ݨ�Ʀr�A�h��stack
	45 ~ 82�� -> �Y�ݨ�Ÿ�
		46 ~ 58�� -> ���w�q�u���v
		60 ~ 82�� -> �ΦѮv�Ъ���k�h��stack
	     	83 ~ 85�� -> �i��|�Spop���A�G�Φ���k���Lpop��
		87 ~ 95�� -> ��X���G







