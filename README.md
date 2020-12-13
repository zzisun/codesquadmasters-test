# codesquadmasters-test
김지선 지원자의 코드스쿼드 마스터즈 2021년도 과정 입학을 위한 온라인 테스트 저장소입니다.

사용 언어: C (Visual studio2019)

## 🔨 3단계: 루빅스 큐브 구현하기
1. 입력: 각 조작법을 한 줄로 입력받는다.
2. 출력: 큐브의 6면을 펼친 상태로 출력한다.
3. Q를 입력받으면 프로그램을 종료하고, 조작 받은 명령의 갯수를 출력시킨다.

#추가 기능 요구사항
1.프로그램 종료 시 경과 시간 출력
2.큐브의 무작위 섞기 기능
3.모든 면을 맞추면 축하 메시지와 함께 프로그램을 자동 종료


## 📝 개요
큐브를 전개하여 입력에 따라 각 픽셀들을 이동시켰다
밀려나간 픽셀은 반대쪽으로 채워지기에 입력 "CUBE> UUU "와 " CUBE> U' " 의 결과가 같다는 점을 사용한다.

## ✏함수 설명
☑ int getInput
  : 사용자입력을 받는다. Q를 입력받은 경우 1을 리턴하여 프로그램을 종료한다.
  
☑ void initCube
  : 큐브의 색을 초기화한다. 
  
  ➡ void makeCol
    : 큐브의 각 면마다 입력받은 색으로 초기화한다.  
  
☑ void mixCube
  : 큐브를 랜덤하게 섞는다.
  
☑ int getInput
  : 사용자입력을 받는다. Q를 입력받은 경우 1을 리턴하여 프로그램을 종료한다.


☑ void rotateCube
  : 입력에 따라 큐브를 조작한다.
  
  ➡ void rotateU
  ➡ void rotateB
  ➡ void rotateL
  ➡ void rotateF
  ➡ void rotateR
  ➡ void rotateD
    : 각 입력에 따라 큐브의 색의 값을 조정한다.    

☑ void execute
  : 사용자의 입력에 따라 해당 방향으로 큐브를 회전시킨다.
  
  ➡ void pushWord
    : 사용자의 입력에 해당하는 큐브의 영역을 방향에 맞게 밀어낸다.
  
  ➡ changeRow
    : 변경된 행을 큐브에 적용시킨다. 
    
  ➡ changeCol
    : 변경된 을 큐브에 적용시킨다. 
    
☑ int checkCube
  : 큐브가 잘 맞춰졌는지 체크한다. 그렇지 않은 경우 1을 리턴
  
   ➡ int changeRow
    : 각 면마다 색깔이 통일되었는지 확인한다. 그렇지 않은 경우 1을 리턴
 
☑ void printCube
  : 변경된 큐브를 출력한다.

☑ void printResult
  : 경과시간, 조작갯수, 인사말을 출력한다.

## 2단계 코딩 요구사항
* 너무 크지 않은 함수 단위로 구현하려고 노력할 것 
* 전역변수의 사용을 자제할 것
* 객체와 배열을 적절히 활용할 것
