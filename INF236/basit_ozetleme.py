import numpy as np

c1 = ['w1', 'w2', 'w3']
c2 = ['w2', 'w4', 'w5']
c3 = ['w1', 'w6', 'w7']
c4 = ['w2', 'w4', 'w8']

sentences = [c1, c2, c3 , c4]

words = set(c1 + c2 + c3 + c4)

scores = dict()
for w in words:
    scores[w] = 0
    for c in sentences:
        if w in c:
            scores[w] += 1
print(scores)

sentence_scores = [0] * len(sentences)
for i, c in enumerate(sentences):
    sentence_score = 0
    for w in c:
        sentence_score += scores[w]
    sentence_scores[i] = sentence_score

print(sentence_scores)

scores = np.array(sentence_scores)
print(scores)
select = scores.argsort()
print(select)

# Generate summary
for i in select[-3:]:
    print(i)
    print(sentences[i])