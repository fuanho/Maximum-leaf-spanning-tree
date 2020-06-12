# Maximum-leaf-spanning-tree

###### tags: `Spanning Tree` `algorithm`

**Warning : If pictures are not working, click on [GitHub+Mermaid](https://chrome.google.com/webstore/detail/github-%20-mermaid/goiiopgdnkogdbjmncgedmgpoajilohe) to add this expansion**

## Description:

Given an undirected connedted graph G, represented by an **adjacency matrix** A(n*n). Please find a tree T that has the maximal number of leaves and contains all the vertices in S. Note that the vertices in G\S may or may not be in the tree T.
  
For the definition of degree, see the Wikipedia [page](https://en.wikipedia.org/wiki/Degree_(graph_theory)).

### Necessary and Unnecessary
```mermaid
    graph LR
    Necessary---Unnecessary
    style Unnecessary fill:#fff
```
### Degree
```mermaid
    graph TD
    subgraph degree3
    A3---B3
    A3---C3
    D3---A3
    end
    subgraph degree2
    A2---B2
    A2---C2
    end
    subgraph degree1
    A1---C1
    end
```
## Example:
### Input data  
9 **// It means this graph has 9 vertices**  
0 1 1 0 0 0 1 0 0  
1 0 0 1 0 0 1 0 0  
1 0 0 0 1 0 0 0 0  
0 1 0 0 0 1 0 0 0  
0 0 1 0 0 0 0 1 0  
0 0 0 1 0 0 0 0 0  
1 1 0 0 0 0 0 1 0  
0 0 0 0 1 0 1 0 1  
0 0 0 0 0 0 0 1 0  
1 1 1 1 1 1 1 1 0 **// A,B,C,D,E,F,G,H are necessary vertices**  
0 **// End**

### Grahp
```mermaid
    graph LR
    A---C
    A---B
    A---G
    B---D
    B---G
    C---E
    D---F
    E---H
    G---H
    H---I
    style I fill:#fff
```
### Spanning Tree
```mermaid
    graph LR
    A---B
    A---C
    C---E
    B---D
    B---G
    G---H
    D---F
```
Because A,B,C,D,G are vertices that have degree more then 1  
**Ans : 5**
## Solution:
See main.cpp
