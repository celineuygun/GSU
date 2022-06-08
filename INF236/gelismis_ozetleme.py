import re
import time
import numpy as np
import pandas as pd
from gensim.models import KeyedVectors
from sklearn.metrics.pairwise import cosine_similarity

start = time.time()

path = './Yasam-Kocum-Uygulamasi/data/'
word_vectors = KeyedVectors.load_word2vec_format(path + 'trmodel', binary=True)

print("total time: ", time.time() - start)

print(cosine_similarity(word_vectors['elma'].reshape(1, -1), 
                  word_vectors['armut'].reshape(1, -1)))

print(cosine_similarity(word_vectors['elma'].reshape(1, -1), 
                  word_vectors['portakal'].reshape(1, -1)))

print(cosine_similarity(word_vectors['elma'].reshape(1, -1), 
                  word_vectors['sandalye'].reshape(1, -1)))

url ='https://raw.githubusercontent.com/sgsinclair/trombone/master/src/main/resources/org/voyanttools/trombone/keywords/stop.tr.turkish-lucene.txt'
data = pd.read_csv(url)
print(data)

stpwrds = set(data[2:].iloc[:, 0].values)

def vectorize(cumle, stpwrds = stpwrds):
    kelimeler = cumle.split()
    vc = np.zeros((1, 400))
    n = 0
    for v in kelimeler:
        if v in stpwrds:
            continue
        try:
            vc += word_vectors[v].reshape(1,400)
            n +=1
        except:
            continue
    vc /= n 
    return vc

sentences = ['Fenerbahçe spor klubü ciddi başarılar kazandı sen ben ben',
             'Damlayan su, taşı deler ben sen o. Ovidius',
             'Hazine, eziyet çekene gözükür ben sen ben',
             'Fenerbahçe vurdu gol oldu',
             'Galatasaray voleybol takımı kazanır']

clean_sentences = [re.sub('[;!@#’‘?.,\'$]', '', s).lower() for s in sentences]
print(clean_sentences)

vectors = [vectorize(s) for s in clean_sentences]
print("vectors: ")
print(vectors)

n = len(sentences)
X = np.concatenate(vectors).reshape(n,1,400)
print(X.shape)

def dot(X, Y):
    result = 0
    for i in range(len(X)):
        result += X[i] * Y[i]
    return result

def norm(X):
    result = dot(X, X)
    return result**0.5

def cos(X, Y):
    return dot(X, X)/ (norm(X) * norm(Y))

cos(X[0].flatten(), X[0].flatten())

cosine_similarity(X[0], X[0])

sim_mat = np.zeros((n,n))
for i in range(n):
    for j in range(n):
        sim_mat[i,j] = cos(X[i].flatten(), X[j].flatten())

print(sim_mat)

scores = sim_mat.sum(axis = 1)
print(scores)

select = scores.argsort()
print(select)

print(select[-3:])

# Generate summary
for i in select[-3:]:
    print(sentences[i])