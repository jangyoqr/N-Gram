# ngram 모델로 문장 생성확률 구하기

문장 s의 출현확률을 ngram 언어모델 기법으로 계산하는 프로그램.
1. unigram 확률

    P(s) = product of P(wi)

2. bigram 확률

    P(s) = product of P(wi | wi-1)

3. trigram 확률

    P(s) = product of P(wi | wi-2, wi-1)
