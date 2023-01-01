# Ratio
> Le projet qui va révolutionner la planète terre !!

Maxime Mathevet et Eric Thiberge

## Principe 
Il s'agit d'une librairie permettant d'exprimer des nombres rationnels (sous la forme $\frac{a}{b}$, $a$ et $b$ étant des entiers) en C++.

## Pourquoi ?
En C++, la représentation usuelle des nombres réels se fait par des nombres à virgules flottantes, codés avec un bit de signe, une mantisse et un exposant. Ce genre de représentation est très efficace sur un large panel d'applications, mais peut montrer ses limites dans certains cas. Notez par exemple la suite : 

$$\left\{\begin{matrix}
u_0 = \frac{1}{3} \\
u_{n+1} = 4u_n-1
\end{matrix}\right.$$

Cette suite est constante avec $u_n=\frac{1}{3}, \forall n\in\mathbb{N}$. Pourtant, en codant cette suite avec des `doubles` codés sur 64 bits, cette suite diverge au bout de quelques itérations. 

## Comment ?

### Nouvelle instance
`Ratio<int> ratio(a, b);`
Ainsi `ratio` vaudra $\frac{a}{b}$.

`Ratio<int> ratio2(a);`
Ainsi `ratio2` vaudra $\frac{a}{1}$.

`Ratio<int> ratio3;`
Ainsi `ratio3` vaudra $\frac{0}{1}$.

### Opérations
Soient `ratio1` et `ratio2` deux variables du type `Ratio` et `real` une variable de type `int` ou `double` par exemple

Il est ainsi possible de faire :

`ratio1 + ratio2;`

`ratio1 - ratio2;`

`ratio1 * ratio2;`

`ratio1 / ratio2;`

`ratio1 + real;`

`ratio1 - real;`

`ratio1 * real;`

`ratio1 / real;`

`real + ratio1;`

`real - ratio1;`

`real * ratio1;`

`real / ratio1;`

`++ratio1;`

`--ratio1;`

Chacunes des opérations précédentes rend les fractions irréductibles.

`ratio1 == ratio2;`

`ratio1 != ratio2;`

`ratio1 < ratio2;`

`ratio1 <= ratio2;`

`ratio1 > ratio2;`

`ratio1 >= ratio2;`

### Méthodes

Plusieurs méthodes viennent avec la librairie : 

#### Getters 
`ratio1.num()` donne le numérateur. 

`ratio1.den()` donne le dénominateur.

#### Fonctions
`ratio1.inverse()` donne l'inverse.

`ratio1.make_irreductible()` rend irreductible.

`ratio1.sqrt()` donne la racine carrée.

`ratio1.cos()` donne le cosinus.

`ratio1.sin()` donne le sinus.

`ratio1.tan()` donne la tengente.

`ratio1.pow(k)` met à la puissance $k$ ( $k$ entier)

`ratio1.exp()` donne l'exponentielle.

`ratio1.log()` donne le logarithme.

`ratio1.int_part()` donne la partie entière

`ratio1.abs()` donne la valeur absolue.

#### Autres
Il est possible d'utiliser la commande `std::cout` pour afficher les Ratio dans le terminal : 

`std::cout << ratio1 << std::endl;`

`>>> a/b`

Il existe une fonction `convert_float_to_ratio(a, n)` prenant en paramètre `a` un nombre à virgule flottante et en paramètre `n` un entier non-signé. Cette fonction permet de convertir un nombre à virgule flottante $a$ en nombre rationnel. $n$ décrit la précision de l'algorithme utilisé. Une valeur entre 10 et 20 permet une précision satisfaisante de manière générale. 


## Compilation

Le projet se compile avec `cmake`. Pour lancer le programme de test utilisez les commandes suivante dans votre terminal. 

À la racine du projet : 
```
mkdir build
cd build
cmake ..
make
./bin/RatioTest
```

## Documentation

Une documentation du projet a été générée avec Doxygen. Il est possible d'y acceder via la commande suivante dans votre terminal :

Dans le dossier builf, après avoir fait la commande `cmake ..` ci-dessus :

```
make html
```

la documentation est accesssible dans : `./build/INTERFACE/doc/doc-doxygen/html/index.html`

Elle est aussi accessible à tout moment sur https://www.ericthiberge.fr/Ratio/