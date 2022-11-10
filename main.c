#include <stdio.h>
#include <windows.h> // system(); �Լ� ���� ���̺귯��
#include <stdlib.h> // rand() �Լ� ���� ���̺귯��
#include <time.h> // time() �Լ� ���� ���̺귯��

#define MAX_SIZE 25

int List_after_sorting[MAX_SIZE]; // ���� �� ����Ʈ (��������)
int List_after_sorting2[MAX_SIZE]; // ���� �� ����Ʈ (��������)
int List_before_sorting[MAX_SIZE]; // ���� �� ����Ʈ

void initializeList () { // ����Ʈ �ʱ�ȭ
    for(int i = 0; i < MAX_SIZE; i++){
        List_after_sorting[i] = 0;
        List_after_sorting2[i] = 0;
        List_before_sorting[i] = 0;  
    }
}

void printList () { // ����Ʈ ���
    printf("���� �� : ");
    for(int i = 0; i < MAX_SIZE; i++){
        printf("%d ", List_before_sorting[i]); // ���� �� ����Ʈ
    }
    printf("\n���� ��[��������] : "); 
    for(int i = 0; i < MAX_SIZE; i++){
        printf("%d ", List_after_sorting[i]); // ���� �� ����Ʈ (��������)
    }
    printf("\n���� ��[��������] : ");
    for(int i = 0; i < MAX_SIZE; i++){
        printf("%d ", List_after_sorting2[i]); // ���� �� ����Ʈ (��������)
    }
    printf("\n\n");
}

void randomNumber () { // ���� ����
    srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX_SIZE; i++) { // 25�� �ݺ�
        List_after_sorting[i] = rand()%101; // ���� ����
        List_after_sorting2[i] = List_after_sorting[i]; // ����
        List_before_sorting[i] = List_after_sorting[i]; // ����
    }
}

void selection () {
    printf("<���� ����>\n");
    randomNumber(); // ���� ����Ʈ �Լ�
    int temp;
    //��������
    for(int i = 0; i < MAX_SIZE; i++){
        for(int j = i+1; j < MAX_SIZE; j++){
            if(List_after_sorting[i]>List_after_sorting[j]) {
                temp = List_after_sorting[i];
                List_after_sorting[i] = List_after_sorting[j];
                List_after_sorting[j] = temp;   
            }
        }
    }
    //��������
    for(int i = 0; i < MAX_SIZE-1; i++){
        for(int j = i+1; j < MAX_SIZE; j++){
            if(List_after_sorting2[i]<List_after_sorting2[j]){
                temp = List_after_sorting2[j];
                List_after_sorting2[j] = List_after_sorting2[i];
                List_after_sorting2[i] = temp;
            }
        }
    }
    printList(); // ��� �ռ� ȣ��
}

void insertion () {
    printf("<���� ����>\n");
    randomNumber();
    int i, j, key;
    //��������
    for(i=1; i<MAX_SIZE; i++){
        key = List_after_sorting[i]; // ���Ե� ������ i��° ������ key�� ����
        for(j=i-1; j>=0 && List_after_sorting[j]>key; j--){
            List_after_sorting[j+1] = List_after_sorting[j]; // ���ڵ�(����ü) ���������� �̵�
        }
        List_after_sorting[j+1] = key; 
    }
    //��������
    for(i=1; i<MAX_SIZE; i++){
        key = List_after_sorting2[i]; // ���Ե� ������ i��° ������ key�� ����
        for(j=i-1; j>=0 && List_after_sorting2[j]<key; j--){
            List_after_sorting2[j+1] = List_after_sorting2[j]; // ���ڵ�(����ü) ���������� �̵�
        }
        List_after_sorting2[j+1] = key;
    }
    printList(); // ��� �ռ� ȣ��
}

void bubble () {
    printf("<���� ����>\n");
    randomNumber();
    int temp;
    //��������
    for(int i = 0; i < MAX_SIZE; i++){
        for(int j = 0; j < MAX_SIZE-1-i; j++){
            if (List_after_sorting[j] > List_after_sorting[j + 1]) {
                temp = List_after_sorting[j];
                List_after_sorting[j] = List_after_sorting[j + 1];
                List_after_sorting[j + 1] = temp;
		    }
        }
    }
    //��������
    for(int i = 0; i < MAX_SIZE; i++){
        for(int j = 0; j < MAX_SIZE-1-i; j++){
            if (List_after_sorting2[j] < List_after_sorting2[j + 1]) {
                temp = List_after_sorting2[j];
                List_after_sorting2[j] = List_after_sorting2[j + 1];
                List_after_sorting2[j + 1] = temp;
		    }
        }
    }
    printList(); // ��� �ռ� ȣ��
}

void quickSort1(int L, int R){
    //��������
    int left = L, right = R;
    int pivot = List_after_sorting[(L + R) / 2]; //pivot�� ��� ����
    int temp;
    do{
        while (List_after_sorting[left] < pivot){ //left�� pivot���� ū ���� �����ų� pivot�� ���� ������ 
            left++;
        }
        while (List_after_sorting[right] > pivot){ //right�� pivot���� ���� ���� �����ų� pivot�� ���� ������ 
            right--;
        }
        if (left<= right){ //left�� right���� ���ʿ� �ִٸ� ��ȯ
            temp = List_after_sorting[left];
            List_after_sorting[left] = List_after_sorting[right];
            List_after_sorting[right] = temp;
            //left ���������� ��ĭ, right �������� ��ĭ �̵�
            left++;
            right--;
        }
    }while (left<= right); 
    if (L < right){
        quickSort1(L, right); //���� �迭 ��������� �ݺ� 
    }
    if (left < R){
        quickSort1(left, R); //������ �迭 ��������� �ݺ� 
    }
}

void quickSort2(int L, int R){
    //��������
    int left = L, right = R;
    int pivot = List_after_sorting2[(L + R) / 2]; //pivot�� ��� ����
    int temp;
    do{
        while (List_after_sorting2[left] > pivot){ //left�� pivot���� ū ���� �����ų� pivot�� ���� ������ 
            left++;
        }
        while (List_after_sorting2[right] < pivot){ //right�� pivot���� ���� ���� �����ų� pivot�� ���� ������ 
            right--;
        }
        if (left<= right){ //left�� right���� ���ʿ� �ִٸ� ��ȯ
            temp = List_after_sorting2[left];
            List_after_sorting2[left] = List_after_sorting2[right];
            List_after_sorting2[right] = temp;
            //left ���������� ��ĭ, right �������� ��ĭ �̵�
            left++;
            right--;
        }
    }while (left<= right); 
    if (L < right){
        quickSort2(L, right); //���� �迭 ��������� �ݺ� 
    }
    if (left < R){
        quickSort2(left, R); //������ �迭 ��������� �ݺ� 
    }
}

void quick () {
    printf("<�� ����>\n");
    randomNumber();
    quickSort1(0, MAX_SIZE-1); //��������
    quickSort2(0, MAX_SIZE-1); //��������
    printList(); // ��� �ռ� ȣ��
}

void mergeSort1_1(int low, int mid, int hight){ //�պ����� - �պ��ܰ� - ��������
    int tempList[MAX_SIZE];
	int i = low; //���� ����
	int j = mid + 1; //������ ����
	int k = 0; //tempList�� �ε��� ��
 
	while(i <= mid && j <= hight){
		if(List_after_sorting[i] <= List_after_sorting[j]){ //�и��� ���� ����Ʈ�� ������ ����Ʈ ��
			tempList[k++] = List_after_sorting[i++];
        }else{
			tempList[k++] = List_after_sorting[j++];
        }
    }
	while(i <= mid){ //������ ���� ���� ����Ʈ�� �ִٸ� tempList�� ���� ä���
		tempList[k++] = List_after_sorting[i++];
    }
    while(j <= hight){ //������ ���� ������ ����Ʈ�� �ִٸ� tempList�ǿ� ���� ä���
		tempList[k++] = List_after_sorting[j++];
    }
    k--;
	while(k >= 0){ //tempList ���� List_after_sorting�� ����
		List_after_sorting[low + k] = tempList[k];
		k--;
	}
}

void mergeSort2_2(int low, int mid, int hight){ //�պ����� - �պ��ܰ� - ��������
    int tempList[MAX_SIZE];
	int i = low; //���� ����
	int j = mid + 1; //������ ����
	int k = 0; //tempList�� �ε��� ��
 
	while(i <= mid && j <= hight){
		if(List_after_sorting2[i] > List_after_sorting2[j]){ //�и��� ���� ����Ʈ�� ������ ����Ʈ ��
			tempList[k++] = List_after_sorting2[i++];
        }else{
			tempList[k++] = List_after_sorting2[j++];
        }
    }
	while(i <= mid){ //������ ���� ���� ����Ʈ�� �ִٸ� tempList�� ���� ä���
		tempList[k++] = List_after_sorting2[i++];
    }
    while(j <= hight){ //������ ���� ������ ����Ʈ�� �ִٸ� tempList�ǿ� ���� ä���
		tempList[k++] = List_after_sorting2[j++];
    }
    k--;
	while(k >= 0){ //tempList ���� List_after_sorting�� ����
		List_after_sorting2[low + k] = tempList[k];
		k--;
	}
}

void mergeSort1(int low, int hight){ //�պ����� - ��������
    int mid;
	if(low < hight){
		mid = (low + hight) / 2;
		mergeSort1(low, mid); //���� ����Ʈ
		mergeSort1(mid + 1, hight); //������ ����Ʈ
		mergeSort1_1(low, mid, hight); //�и��� ����Ʈ ���� �Լ�
	}
}

void mergeSort2(int low, int hight){ //�պ����� - ��������
    int mid;
	if(low < hight){
		mid = (low + hight) / 2;
		mergeSort2(low, mid); //���� ����Ʈ
		mergeSort2(mid + 1, hight); //������ ����Ʈ
		mergeSort2_2(low, mid, hight); //�и��� ����Ʈ ���� �Լ�
	}
}

void merge () {
    printf("<�պ� ����>\n");
    randomNumber();
    mergeSort1(0, MAX_SIZE-1); //��������
    mergeSort2(0, MAX_SIZE-1); //��������
    printList(); // ��� �ռ� ȣ��
}
 
void heapify1(int size1){ //�� ���� ����� (��������)
	for(int i=1;i<size1;++i){
		int child = i;
		do{
			int root = (child-1)/2;
			if(List_after_sorting[root]<List_after_sorting[child]){ //�ڽ� ��尡 �θ� ��庸�� ũ�� ��ȯ
				int temp = List_after_sorting[root];
				List_after_sorting[root] = List_after_sorting[child];
				List_after_sorting[child] = temp;
			}
			child = root;
		}while(child!=0); //�ֻ�� ������ ����
	}
}

void heap1(int *size1){ //�ֻ�� ���� ���ϴ� ��� ��ü (��������)
	int temp = List_after_sorting[0];
	List_after_sorting[0] = List_after_sorting[*size1-1];
	List_after_sorting[*size1-1] = temp;
	--(*size1);
}

void heapify2(int size2){ //�� ���� ����� (��������)
	for(int i=1;i<size2;++i){
		int child = i;
		do{
			int root = (child-1)/2;
			if(List_after_sorting2[root]>List_after_sorting2[child]){ //�ڽ� ��尡 �θ� ��庸�� ũ�� ��ȯ
				int temp = List_after_sorting2[root];
				List_after_sorting2[root] = List_after_sorting2[child];
				List_after_sorting2[child] = temp;
			}
			child = root;
		}while(child!=0); //�ֻ�� ������ ����
	}
}

void heap2(int *size2){ //�ֻ�� ���� ���ϴ� ��� ��ü (��������)
	int temp = List_after_sorting2[0];
	List_after_sorting2[0] = List_after_sorting2[*size2-1];
	List_after_sorting2[*size2-1] = temp;
	--(*size2);
}

void heapSort () {
    printf("<�� ����>\n");
    randomNumber();
    int size1 = MAX_SIZE;
    for(int i=0;i<MAX_SIZE;++i){ //��������
		heapify1(size1); //������ ����� �Լ�
		heap1(&size1); 
	}
    int size2 = MAX_SIZE;
    for(int i=0;i<MAX_SIZE;++i){ //��������
		heapify2(size2); //������ ����� �Լ�
		heap2(&size2);
	}
    printList(); // ��� �ռ� ȣ��
}

void quit () {
    printf("<����>");
    exit(0);
}

void guide () {
    printf("***********************************\n");
    printf("*** �������� ���� ���α׷� ���� ***\n");
    printf("***                             ***\n");
    printf("*** 1. ����(selection) ����     ***\n");
    printf("*** 2. ����(insertion) ����     ***\n");
    printf("*** 3. ����(bubble) ����        ***\n");
    printf("*** 4. ��(quick) ����           ***\n");
    printf("*** 5. �պ�(merge) ����         ***\n");
    printf("*** 6. ��(heap) ����            ***\n");
    printf("*** 7. ����(quit) ����          ***\n");
    printf("***********************************\n");
}

void banner () {
    printf("  mmmm                  m	   m    m                   #   #\n");
    printf(" #\"   \"  mmm    m mm  mm#mm  	   #    #  mmm   m mm    mmm#   #     mmm    m mm\n");
    printf(" \"#mmm  #\" \"#   #\"  \"   #          #mmmm# \"   #  #\"  #  #\" \"#   #    #\"  #   #\"  \"\n");
    printf("     \"# #   #   #       #          #    # m\"\"\"#  #   #  #   #   #    #\"\"\"\"   #\n");
    printf(" \"mmm#\" \"#m#\"   #       \"mm        #    # \"mm\"#  #   #  \"#m##   \"mm  \"#mm\"   #\n\n");
}

int main () {
    banner(); // ��� �Լ� (Sort Handler)
    guide(); // ���� ��ȣ ����
    int Select_Features;
    while(1){
        printf("\n��ȣ �Է� : ");
        scanf("%d", &Select_Features); // ��ȣ �Է�
        switch (Select_Features) // �Է� ��ȣ ���� 
        {
            case 1:  
                selection(); // ���� ���� �Լ� ȣ��
                break;
            case 2:
                insertion(); // ���� ���� �Լ� ȣ��
                break;
            case 3:
                bubble(); // ���� ���� �Լ� ȣ��
                break;
            case 4: 
                quick(); // �� ���� �Լ� ȣ��
                break;
            case 5: 
                merge(); // �պ� �����Լ� ȣ��
                break;
            case 6:
                heapSort(); // �� ���� �Լ� ȣ��
                break;
            case 7:
                quit(); // ���� �Լ� ȣ��
                break;
            default:
                printf("<��ȣ ����>");   
                Sleep(1000);
                system( "cls" );
                guide(); // ���� ��ȣ ����
                break;
        }
        initializeList(); //����Ʈ �ʱ�ȭ �Լ� ȣ��
    }
}