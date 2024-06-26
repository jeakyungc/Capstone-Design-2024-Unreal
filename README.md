# Method
건설 및 공업 환경에서의 데이터 셋 구축은 위험 및 발생상황 자체의 희귀성과 기존 AI 기반 합성 방식의 고품질 데이터 의존성의 문제로 모델을 구축하는데 어려움이 있어 왔다. 건설환경 특히 안전 모니터링이라는 분야의 특성상 사용되는 CV 모델이 효율적이고 정확한 예측을 수행하기 위해, 고품질 데이터에 크게 의존하기 때문에 데이터셋의 확보는 중요한 문제이다. 이에 합성 데이터 생성의이를 절차적 생성의 한 기법인 [WFC](https://github.com/mxgmn/WaveFunctionCollapse)의 생성 방법을 응용한 HWFC을 사용하였다. 이는 기본 WFC와 비교하여, Hierarchical WFC(HWFC)는 합성 데이터 생성 시 의도를 효과적으로 반영할 수 있으며, 인공 신경망을 사용한 합성 데이터 접근방식보다 적은 양의 사전 학습 데이터와 간소화된 모델로 합성 데이터를 생성할 수 있다는 장점이 있다. HWFC는 가중치가 적용된 유방향 그래프를 기반으로 인접 행렬을 생성해 이를 제약조건으로 제약조건 해결 알고리즘을 통해 합성 데이터를 생성한다.

***
# Demo
## 1. Section Meta Tile 설정
<img src="/image/1.png" alt="image1" width="500" height="300">
## 2. Directional Acyclic Graph 설정 Meta-tile과 asset Data을 연결한다.
<img src="/image/2.png" alt="image1" width="500" height="300">
## 3. Tile Grid의 Section(MetaTile) 설정
<img src="/image/3.png" alt="image1" width="500" height="300">
## 4. 다양한 size의 tile을 설정 할 수 있다.
<img src="/image/4.png" alt="image1" width="500" height="300">
## 5. 생성된 Demo image
<img src="/image/5.png" alt="image1" width="500" height="300">

***
# Future Study
- 디자이너의 설정값에 의존하는 문제 -> 이미지의 위치 관계등을 추론하는 CV 기법을 사용하여 발전 시킬 계획입니다.
- 3D 에셋의 퀄리티에 의존적인 문제
