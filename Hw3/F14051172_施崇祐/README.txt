
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