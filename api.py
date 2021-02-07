from flask import Flask, jsonify
import random
from math import floor
def binary_search(Array, Search_Term):    
    n = len(Array)
    L = 0
    R = n-1
    while L <= R:
        mid = floor((L+R)/2)
        if Array[mid] < Search_Term:
            L = mid + 1
        elif Array[mid] > Search_Term:
            R = mid - 1
        else:
            return mid
    return -1
def linear_search(lista,valor):
    for x in range(len(lista)):
        if lista[x]==valor:
            return x
    return -1
app = Flask(__name__)
@app.route("/")
def index():
    return 'Hello World'

@app.route("/binary/<int:cant>/<int:value>")
def binary(cant, value):
    lista = []
    lista = random.sample(range(10000), cant)
    lista = sorted(lista)
    indice = binary_search(lista, value)
    if indice >= 0:
        return f"Binary: {lista[indice]} esta en la posicion {indice}"
    else:
        return "no se encontro el valor"
@app.route("/linear/<int:cant>/<int:value>")
def linear(cant, value):
    lista = []
    lista = random.sample(range(10000), cant)
    indice = linear_search(lista, value)
    if indice >= 0:
        return f"Linear: {lista[indice]} esta en la posicion {indice}"
    else:
        return "no se encontro el valor"
if __name__ == '__main__':
    app.run(debug = True)
