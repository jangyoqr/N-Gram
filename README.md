# ngram 모델로 문장 생성확률 구하기

1) 대용량 텍스트 파일에서 각 word(어절)에 대한 unigram, bigram, trigram 빈도
2) unigram, bigram, trigram 파일로부터 각 word n-gram 확률을 계산하는 프로그램 작성
    P(w) = freq(w) / N
    P(wi | wi-1) = freq(wi-1,wi) / freq(wi-1)
    P(wi | wi-2,wi-1) = freq(wi-2,wi-1,wi) / freq(wi-2,wi-1)
3) 입력 문장에 대한 출현확률 P(s)를 3가지 방법
    Puni(s), Pbi(s), Ptri(s)

문장 s의 출현확률을 ngram 언어모델 기법으로 계산하는 프로그램.
1. unigram 확률

    P(s) = product of P(wi)

2. bigram 확률

    P(s) = product of P(wi | wi-1)

3. trigram 확률

    P(s) = product of P(wi | wi-2, wi-1)
