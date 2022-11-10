#include <stdio.h>
#include <windows.h> // system(); 함수 포함 라이브러리
#include <stdlib.h> // rand() 함수 포함 라이브러리
#include <time.h> // time() 함수 포함 라이브러리

#define MAX_SIZE 25

int List_after_sorting[MAX_SIZE]; // 정렬 후 리스트 (오름차순)
int List_after_sorting2[MAX_SIZE]; // 정렬 후 리스트 (내림차순)
int List_before_sorting[MAX_SIZE]; // 정렬 전 리스트

void initializeList () { // 리스트 초기화
    for(int i = 0; i < MAX_SIZE; i++){
        List_after_sorting[i] = 0;
        List_after_sorting2[i] = 0;
        List_before_sorting[i] = 0;  
    }
}

void printList () { // 리스트 출력
    printf("정렬 전 : ");
    for(int i = 0; i < MAX_SIZE; i++){
        printf("%d ", List_before_sorting[i]); // 정렬 전 리스트
    }
    printf("\n정렬 후[오름차순] : "); 
    for(int i = 0; i < MAX_SIZE; i++){
        printf("%d ", List_after_sorting[i]); // 정렬 후 리스트 (오름차순)
    }
    printf("\n정렬 후[내림차순] : ");
    for(int i = 0; i < MAX_SIZE; i++){
        printf("%d ", List_after_sorting2[i]); // 정렬 후 리스트 (내림차순)
    }
    printf("\n\n");
}

void randomNumber () { // 난수 삽입
    srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX_SIZE; i++) { // 25번 반복
        List_after_sorting[i] = rand()%101; // 난수 생성
        List_after_sorting2[i] = List_after_sorting[i]; // 복사
        List_before_sorting[i] = List_after_sorting[i]; // 복사
    }
}

void selection () {
    printf("<선택 정렬>\n");
    randomNumber(); // 난수 리스트 함수
    int temp;
    //오름차순
    for(int i = 0; i < MAX_SIZE; i++){
        for(int j = i+1; j < MAX_SIZE; j++){
            if(List_after_sorting[i]>List_after_sorting[j]) {
                temp = List_after_sorting[i];
                List_after_sorting[i] = List_after_sorting[j];
                List_after_sorting[j] = temp;   
            }
        }
    }
    //내림차순
    for(int i = 0; i < MAX_SIZE-1; i++){
        for(int j = i+1; j < MAX_SIZE; j++){
            if(List_after_sorting2[i]<List_after_sorting2[j]){
                temp = List_after_sorting2[j];
                List_after_sorting2[j] = List_after_sorting2[i];
                List_after_sorting2[i] = temp;
            }
        }
    }
    printList(); // 출력 합수 호출
}

void insertion () {
    printf("<삽입 정렬>\n");
    randomNumber();
    int i, j, key;
    //오름차순
    for(i=1; i<MAX_SIZE; i++){
        key = List_after_sorting[i]; // 삽입될 숫자인 i번째 정수를 key에 복사
        for(j=i-1; j>=0 && List_after_sorting[j]>key; j--){
            List_after_sorting[j+1] = List_after_sorting[j]; // 레코드(구조체) 오른쪽으로 이동
        }
        List_after_sorting[j+1] = key; 
    }
    //내림차순
    for(i=1; i<MAX_SIZE; i++){
        key = List_after_sorting2[i]; // 삽입될 숫자인 i번째 정수를 key에 복사
        for(j=i-1; j>=0 && List_after_sorting2[j]<key; j--){
            List_after_sorting2[j+1] = List_after_sorting2[j]; // 레코드(구조체) 오른쪽으로 이동
        }
        List_after_sorting2[j+1] = key;
    }
    printList(); // 출력 합수 호출
}

void bubble () {
    printf("<버블 정렬>\n");
    randomNumber();
    int temp;
    //오름차순
    for(int i = 0; i < MAX_SIZE; i++){
        for(int j = 0; j < MAX_SIZE-1-i; j++){
            if (List_after_sorting[j] > List_after_sorting[j + 1]) {
                temp = List_after_sorting[j];
                List_after_sorting[j] = List_after_sorting[j + 1];
                List_after_sorting[j + 1] = temp;
		    }
        }
    }
    //내림차순
    for(int i = 0; i < MAX_SIZE; i++){
        for(int j = 0; j < MAX_SIZE-1-i; j++){
            if (List_after_sorting2[j] < List_after_sorting2[j + 1]) {
                temp = List_after_sorting2[j];
                List_after_sorting2[j] = List_after_sorting2[j + 1];
                List_after_sorting2[j + 1] = temp;
		    }
        }
    }
    printList(); // 출력 합수 호출
}

void quickSort1(int L, int R){
    //오름차순
    int left = L, right = R;
    int pivot = List_after_sorting[(L + R) / 2]; //pivot을 가운데 설정
    int temp;
    do{
        while (List_after_sorting[left] < pivot){ //left가 pivot보다 큰 값을 만나거나 pivot을 만날 때까지 
            left++;
        }
        while (List_after_sorting[right] > pivot){ //right가 pivot보다 작은 값을 만나거나 pivot을 만날 때까지 
            right--;
        }
        if (left<= right){ //left가 right보다 왼쪽에 있다면 교환
            temp = List_after_sorting[left];
            List_after_sorting[left] = List_after_sorting[right];
            List_after_sorting[right] = temp;
            //left 오른쪽으로 한칸, right 왼쪽으로 한칸 이동
            left++;
            right--;
        }
    }while (left<= right); 
    if (L < right){
        quickSort1(L, right); //왼쪽 배열 재귀적으로 반복 
    }
    if (left < R){
        quickSort1(left, R); //오른쪽 배열 재귀적으로 반복 
    }
}

void quickSort2(int L, int R){
    //내림차순
    int left = L, right = R;
    int pivot = List_after_sorting2[(L + R) / 2]; //pivot을 가운데 설정
    int temp;
    do{
        while (List_after_sorting2[left] > pivot){ //left가 pivot보다 큰 값을 만나거나 pivot을 만날 때까지 
            left++;
        }
        while (List_after_sorting2[right] < pivot){ //right가 pivot보다 작은 값을 만나거나 pivot을 만날 때까지 
            right--;
        }
        if (left<= right){ //left가 right보다 왼쪽에 있다면 교환
            temp = List_after_sorting2[left];
            List_after_sorting2[left] = List_after_sorting2[right];
            List_after_sorting2[right] = temp;
            //left 오른쪽으로 한칸, right 왼쪽으로 한칸 이동
            left++;
            right--;
        }
    }while (left<= right); 
    if (L < right){
        quickSort2(L, right); //왼쪽 배열 재귀적으로 반복 
    }
    if (left < R){
        quickSort2(left, R); //오른쪽 배열 재귀적으로 반복 
    }
}

void quick () {
    printf("<퀵 정렬>\n");
    randomNumber();
    quickSort1(0, MAX_SIZE-1); //오름차순
    quickSort2(0, MAX_SIZE-1); //내림차순
    printList(); // 출력 합수 호출
}

void mergeSort1_1(int low, int mid, int hight){ //합병정렬 - 합병단계 - 오름차순
    int tempList[MAX_SIZE];
	int i = low; //왼쪽 시작
	int j = mid + 1; //오른쪽 시작
	int k = 0; //tempList의 인덱스 값
 
	while(i <= mid && j <= hight){
		if(List_after_sorting[i] <= List_after_sorting[j]){ //분리된 왼쪽 리스트과 오른쪽 리스트 비교
			tempList[k++] = List_after_sorting[i++];
        }else{
			tempList[k++] = List_after_sorting[j++];
        }
    }
	while(i <= mid){ //비교하지 않은 왼쪽 리스트가 있다면 tempList에 전부 채우기
		tempList[k++] = List_after_sorting[i++];
    }
    while(j <= hight){ //비교하지 않은 오른쪽 리스트가 있다면 tempList의에 전부 채우기
		tempList[k++] = List_after_sorting[j++];
    }
    k--;
	while(k >= 0){ //tempList 값을 List_after_sorting에 복사
		List_after_sorting[low + k] = tempList[k];
		k--;
	}
}

void mergeSort2_2(int low, int mid, int hight){ //합병정렬 - 합병단계 - 내림차순
    int tempList[MAX_SIZE];
	int i = low; //왼쪽 시작
	int j = mid + 1; //오른쪽 시작
	int k = 0; //tempList의 인덱스 값
 
	while(i <= mid && j <= hight){
		if(List_after_sorting2[i] > List_after_sorting2[j]){ //분리된 왼쪽 리스트과 오른쪽 리스트 비교
			tempList[k++] = List_after_sorting2[i++];
        }else{
			tempList[k++] = List_after_sorting2[j++];
        }
    }
	while(i <= mid){ //비교하지 않은 왼쪽 리스트가 있다면 tempList에 전부 채우기
		tempList[k++] = List_after_sorting2[i++];
    }
    while(j <= hight){ //비교하지 않은 오른쪽 리스트가 있다면 tempList의에 전부 채우기
		tempList[k++] = List_after_sorting2[j++];
    }
    k--;
	while(k >= 0){ //tempList 값을 List_after_sorting에 복사
		List_after_sorting2[low + k] = tempList[k];
		k--;
	}
}

void mergeSort1(int low, int hight){ //합병정렬 - 오름차순
    int mid;
	if(low < hight){
		mid = (low + hight) / 2;
		mergeSort1(low, mid); //왼쪽 리스트
		mergeSort1(mid + 1, hight); //오른쪽 리스트
		mergeSort1_1(low, mid, hight); //분리된 리스트 정렬 함수
	}
}

void mergeSort2(int low, int hight){ //합병정렬 - 내림차순
    int mid;
	if(low < hight){
		mid = (low + hight) / 2;
		mergeSort2(low, mid); //왼쪽 리스트
		mergeSort2(mid + 1, hight); //오른쪽 리스트
		mergeSort2_2(low, mid, hight); //분리된 리스트 정렬 함수
	}
}

void merge () {
    printf("<합병 정렬>\n");
    randomNumber();
    mergeSort1(0, MAX_SIZE-1); //오름차순
    mergeSort2(0, MAX_SIZE-1); //내림차순
    printList(); // 출력 합수 호출
}
 
void heapify1(int size1){ //힙 상태 만들기 (오름차순)
	for(int i=1;i<size1;++i){
		int child = i;
		do{
			int root = (child-1)/2;
			if(List_after_sorting[root]<List_after_sorting[child]){ //자식 노드가 부모 노드보다 크면 교환
				int temp = List_after_sorting[root];
				List_after_sorting[root] = List_after_sorting[child];
				List_after_sorting[child] = temp;
			}
			child = root;
		}while(child!=0); //최상단 노드까지 점검
	}
}

void heap1(int *size1){ //최상단 노드와 최하단 노드 교체 (오름차순)
	int temp = List_after_sorting[0];
	List_after_sorting[0] = List_after_sorting[*size1-1];
	List_after_sorting[*size1-1] = temp;
	--(*size1);
}

void heapify2(int size2){ //힙 상태 만들기 (내림차순)
	for(int i=1;i<size2;++i){
		int child = i;
		do{
			int root = (child-1)/2;
			if(List_after_sorting2[root]>List_after_sorting2[child]){ //자식 노드가 부모 노드보다 크면 교환
				int temp = List_after_sorting2[root];
				List_after_sorting2[root] = List_after_sorting2[child];
				List_after_sorting2[child] = temp;
			}
			child = root;
		}while(child!=0); //최상단 노드까지 점검
	}
}

void heap2(int *size2){ //최상단 노드와 최하단 노드 교체 (내림차순)
	int temp = List_after_sorting2[0];
	List_after_sorting2[0] = List_after_sorting2[*size2-1];
	List_after_sorting2[*size2-1] = temp;
	--(*size2);
}

void heapSort () {
    printf("<힙 정렬>\n");
    randomNumber();
    int size1 = MAX_SIZE;
    for(int i=0;i<MAX_SIZE;++i){ //오름차순
		heapify1(size1); //힙상태 만드는 함수
		heap1(&size1); 
	}
    int size2 = MAX_SIZE;
    for(int i=0;i<MAX_SIZE;++i){ //내림차순
		heapify2(size2); //힙상태 만드는 함수
		heap2(&size2);
	}
    printList(); // 출력 합수 호출
}

void quit () {
    printf("<종료>");
    exit(0);
}

void guide () {
    printf("***********************************\n");
    printf("*** 여러가지 정렬 프로그램 구현 ***\n");
    printf("***                             ***\n");
    printf("*** 1. 선택(selection) 정렬     ***\n");
    printf("*** 2. 삽입(insertion) 정렬     ***\n");
    printf("*** 3. 버블(bubble) 정렬        ***\n");
    printf("*** 4. 퀵(quick) 정렬           ***\n");
    printf("*** 5. 합병(merge) 정렬         ***\n");
    printf("*** 6. 힙(heap) 정렬            ***\n");
    printf("*** 7. 종료(quit) 정렬          ***\n");
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
    banner(); // 배너 함수 (Sort Handler)
    guide(); // 정렬 번호 보기
    int Select_Features;
    while(1){
        printf("\n번호 입력 : ");
        scanf("%d", &Select_Features); // 번호 입력
        switch (Select_Features) // 입력 번호 구분 
        {
            case 1:  
                selection(); // 선택 정렬 함수 호출
                break;
            case 2:
                insertion(); // 삽입 정렬 함수 호출
                break;
            case 3:
                bubble(); // 버블 정렬 함수 호출
                break;
            case 4: 
                quick(); // 퀵 정렬 함수 호출
                break;
            case 5: 
                merge(); // 합병 정렬함수 호출
                break;
            case 6:
                heapSort(); // 힙 정렬 함수 호출
                break;
            case 7:
                quit(); // 종료 함수 호출
                break;
            default:
                printf("<번호 오류>");   
                Sleep(1000);
                system( "cls" );
                guide(); // 정렬 번호 보기
                break;
        }
        initializeList(); //리스트 초기화 함수 호출
    }
}