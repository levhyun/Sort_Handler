#include <stdio.h>
#include <windows.h> // system(); �Լ� ���� ���̺귯��
#include <stdlib.h> // rand() �Լ� ���� ���̺귯��
#include <time.h> // time() �Լ� ���� ���̺귯��

#define MAX_SIZE 25

int List_after_sorting[MAX_SIZE]; // ���� �� ����Ʈ (��������)
int List_after_sorting2[MAX_SIZE]; // ���� �� ����Ʈ (��������)
int List_before_sorting[MAX_SIZE]; // ���� �� ����Ʈ

void initializeList () { // ����Ʈ �ʱ�ȭ
    for(int i = 0; i < MAX_SIZE; i++){ // 0���� 24���� �ݺ�
        List_after_sorting[i] = 0; // i��° �� 0���� �ʱ�ȭ
        List_after_sorting2[i] = 0; // i��° �� 0���� �ʱ�ȭ
        List_before_sorting[i] = 0; // i��° �� 0���� �ʱ�ȭ
    }
}

void printList () { // ����Ʈ ���
    printf("���� �� : ");
    for(int i = 0; i < MAX_SIZE; i++){ // 0���� 24���� �ݺ�
        printf("%d ", List_before_sorting[i]); // ���� �� ����Ʈ ���
    }
    printf("\n���� ��[��������] : "); 
    for(int i = 0; i < MAX_SIZE; i++){ // 0���� 24���� �ݺ�
        printf("%d ", List_after_sorting[i]); // ���� �� ����Ʈ (��������) ���
    }
    printf("\n���� ��[��������] : ");
    for(int i = 0; i < MAX_SIZE; i++){ // 0���� 24���� �ݺ�
        printf("%d ", List_after_sorting2[i]); // ���� �� ����Ʈ (��������) ���
    }
    printf("\n\n");
}

void randomNumber () { // ���� ����
    srand((unsigned int)time(NULL)); // ����ɶ����� �������� �����°��� ����
	for (int i = 0; i < MAX_SIZE; i++) { // 0���� 24���� �ݺ�
        List_after_sorting[i] = rand()%101; // 0~100 ������ ���� ������ ����Ʈ�� ����
        List_after_sorting2[i] = List_after_sorting[i]; // ����
        List_before_sorting[i] = List_after_sorting[i]; // ����
    }
}

void selection () {
    printf("<���� ����>\n");
    randomNumber(); // ���� ����Ʈ �Լ�
    int temp; 
    //��������
    for(int i = 0; i < MAX_SIZE; i++){ // 0���� 24���� �ݺ�
        for(int j = i+1; j < MAX_SIZE; j++){  // i+1���� 24���� �ݺ�
            if(List_after_sorting[i]>List_after_sorting[j]) { //���� i��° ���� j��° ������ Ŭ��� ���� ����
                /*  
                    ���� i��° ���� j��° ������ Ŭ��� 
                    ���������̹Ƿ� ū���ϼ��� �ڿ� �־�� �ϱ⿡ 
                    i��° ���� j��° ���� ��ġ�� �ٲ۴�.
                */
                temp = List_after_sorting[i];
                List_after_sorting[i] = List_after_sorting[j];
                List_after_sorting[j] = temp;   
            }
        }
    }
    //��������
    for(int i = 0; i < MAX_SIZE-1; i++){ // 0���� 24���� �ݺ�
        for(int j = i+1; j < MAX_SIZE; j++){ // i+1���� 24���� �ݺ�
            if(List_after_sorting2[i]<List_after_sorting2[j]){ //���� i��° ���� j��° ������ ������� ���� ����
                /*  
                    ���� i��° ���� j��° ������ Ŭ��� 
                    ���������̹Ƿ� �������ϼ��� �տ� �־�� �ϱ⿡ 
                    i��° ���� j��° ���� ��ġ�� �ٲ۴�.
                */
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
    randomNumber(); // ���� ����Ʈ �Լ�
    int i, j, key;
    //��������
    for( i=1; i<MAX_SIZE; i++){ // 1���� 24���� �ݺ�
        key = List_after_sorting[i]; // ���Ե� ������ i��° ������ key�� ����
        for( j=i-1; j>=0 && List_after_sorting[j]>key; j--){ 
            // i-1���� j�� 0���� ũ�ų� ������ ���� �ݺ�
            // j��° ���� key���� Ŭ ��� �ݺ��� �� ��ɾ� ����.
            List_after_sorting[j+1] = List_after_sorting[j]; // ���ڵ�(����ü) ���������� �̵�
        }
        List_after_sorting[j+1] = key; // ����
    }
    //��������
    for( i=1; i<MAX_SIZE; i++){
        key = List_after_sorting2[i]; // ���Ե� ������ i��° ������ key�� ����
        for( j=i-1; j>=0 && List_after_sorting2[j]<key; j--){
            // i-1���� j�� 0���� ũ�ų� ������ ���� �ݺ�
            // j��° ���� key���� ���� ��� �ݺ��� �� ��ɾ� ����.
            List_after_sorting2[j+1] = List_after_sorting2[j]; // ���ڵ�(����ü) ���������� �̵�
        }
        List_after_sorting2[j+1] = key; // ����
    }
    printList(); // ��� �ռ� ȣ��
}

void bubble () {
    printf("<���� ����>\n");
    randomNumber(); // ���� ����Ʈ �Լ�
    int temp;
    //��������
    for(int i = 0; i < MAX_SIZE; i++){ // 0���� 24���� �ݺ�
        for(int j = 0; j < MAX_SIZE-1-i; j++){ // 0���� 23-i���� �ݺ�
            if (List_after_sorting[j] > List_after_sorting[j + 1]) { 
                // j��° ���� ����ĭ�� ������ Ŭ��� ���� �Ǿ� ��ġ�� �ٲ۴�
                temp = List_after_sorting[j];
                List_after_sorting[j] = List_after_sorting[j + 1];
                List_after_sorting[j + 1] = temp;
		    }
        }
    }
    //��������
    for(int i = 0; i < MAX_SIZE; i++){ // 0���� 24���� �ݺ�
        for(int j = 0; j < MAX_SIZE-1-i; j++){ // 0���� 23-i���� �ݺ�
            if (List_after_sorting2[j] < List_after_sorting2[j + 1]) {
                // j��° ���� ����ĭ�� ������ ���� ��� ���� �Ǿ� ��ġ�� �ٲ۴�
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
        while (List_after_sorting2[left] > pivot){ //left�� pivot���� ���� ���� �����ų� pivot�� ���� ������ 
            left++;
        }
        while (List_after_sorting2[right] < pivot){ //right�� pivot���� ū ���� �����ų� pivot�� ���� ������ 
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
    randomNumber(); // ���� ����Ʈ �Լ�
    quickSort1(0, MAX_SIZE-1); //�������� (������ ������ ���� �Ű������� ������)
    quickSort2(0, MAX_SIZE-1); //�������� (������ ������ ���� �Ű������� ������)
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
		mergeSort1(low, mid); // mid���� ����Ʈ
		mergeSort1(mid + 1, hight); // mid������ ����Ʈ
		mergeSort1_1(low, mid, hight); //�и��� ����Ʈ ���� �Լ�
	}
}

void mergeSort2(int low, int hight){ //�պ����� - ��������
    int mid;
	if(low < hight){
		mid = (low + hight) / 2;
		mergeSort2(low, mid); // mid���� ����Ʈ
		mergeSort2(mid + 1, hight); // mid������ ����Ʈ
		mergeSort2_2(low, mid, hight); //�и��� ����Ʈ ���� �Լ�
	}
}

void merge () {
    printf("<�պ� ����>\n");
    randomNumber(); // ���� ����Ʈ �Լ�
    mergeSort1(0, MAX_SIZE-1); //�������� (������ ������ ���� �Ű������� ������)
    mergeSort2(0, MAX_SIZE-1); //�������� (������ ������ ���� �Ű������� ������)
    printList(); // ��� �ռ� ȣ�� 
}

void MinHeapSort () { //��������
    printf("<�� ����>\n");
    randomNumber(); // ���� ����Ʈ �Լ�
    
}

void MaxHeap_Insert(int h[], int item, int heap_index){ // �������� �ִ���Ʈ���� ����
    int i = heap_index;
    while((i!=1) && (item>h[i/2])){ // ����Ʈ���� �ƴϰ� item ���� �θ𰪺��� Ŭ��� ��
        h[i]=h[i/2]; // �θ� ���� �ڽ����� �ű�.
        i/=2;
    }
    h[i]=item; // �ִ� �� Ʈ���� item����
}

int MaxHeap_Delete(int h[], int heap_index){
    int parent, child, item, temp;
    item = h[1]; // ������ item
    temp = h[heap_index]; // ������ ���� ���� temp�� ����
    parent = 1;
    child = 2;
    while(child<=heap_index){
        if((child<heap_index) && (h[child] < h[child+1])){
            child++; // �ڽ� �� �� ū �� ����
        }
        if(temp>=h[child]){
            break;
        }
        h[parent]=h[child]; // �ڽ� ���� �θ��
        parent=child; // �Ʒ� �ܰ�� �̵�
        child*=2; // �Ʒ� �ܰ�� �̵�
    }
    h[parent]=temp;
    return item;
}

void MaxHeapSort () { //��������
    printf("<�� ����>\n");
    randomNumber(); // ���� ����Ʈ �Լ�
    int h[MAX_SIZE] = {0}, heap_index = 0;
    for(int i=0;i<MAX_SIZE;i++){ // �ִ� �� ����
		heap_index++;
        MaxHeap_Insert(h, List_after_sorting[i], heap_index); // ������ ���� �Լ� ȣ��
	}
    for(int i=MAX_SIZE-1;i>=0;i--){ // �ִ� �� ����
        List_after_sorting[i]=MaxHeap_Delete(h, heap_index); // ������ ���� �Լ� ȣ��
        heap_index--;
	}
}

void heapSort () { //��������
    printf("<�� ����>\n");
    randomNumber(); // ���� ����Ʈ �Լ�
    MaxHeapSort(); // ��������
    // MinHeapSort(); //��������
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
    int Select_Features; // ���� ���� ��ȣ �Էµ� ����
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
                Sleep(1000); // 1�� ���
                system( "cls" ); // ����â �����
                guide(); // ���� ��ȣ ����
                break;
        }
        initializeList(); //����Ʈ �ʱ�ȭ �Լ� ȣ��
    }
}