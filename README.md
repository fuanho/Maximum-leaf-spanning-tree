# Maximum-leaf-spanning-tree

###### tags: `Spanning Tree` `algorithm`

## Description:

Giving and undirected connedted graph using **adjacency matrix** A(n*n). Find a spanning tree which degree more then 1 nodes are minimum(i.e. maxmum leaf).  
  
But this graph has some rules. First not all nodes need to be connected in final spanning tree. Its depend on spanning tree if the node is **unnecessary** you can chose either include or not include.  
The other rule is the definition of degree you can see the degree to learn more.  

### Necessary and Unnecessary
```mermaid
    graph LR
    Necessary---Unnecessary
    style Unnecessary fill:#fff
```
### Degree
```mermaid
    graph TD
    subgraph degree2
    A2---B2
    A2---C2
    end
    subgraph degree1
    A1---C1
    end
```
## Excample:
### Input data  
9 // It means this graph has 9 nodes  
0 1 1 0 0 0 1 0 0  
1 0 0 1 0 0 1 0 0  
1 0 0 0 1 0 0 0 0  
0 1 0 0 0 1 0 0 0  
0 0 1 0 0 0 0 1 0  
0 0 0 1 0 0 0 0 0  
1 1 0 0 0 0 0 1 0  
0 0 0 0 1 0 1 0 1  
0 0 0 0 0 0 0 1 0  
1 1 1 1 1 1 1 1 0 // A,B,C,D,E,F,G,H is necessary node  
0 // End

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
Because nodes A,B,C,D,G degree more then 1  
**Ans : 5**
## Solution:
See main.cpp