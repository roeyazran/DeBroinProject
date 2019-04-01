//
// Created by roei_ on 30/03/2019.
//

#ifndef DEBROINPROJECT_DEBRUJINGRAPH_H
#define DEBROINPROJECT_DEBRUJINGRAPH_H

#include <vector>
#include <cmath>
#include <bitset>
using namespace std;

template <ssize_t NodeLen>
class GraphNode{
    bitset<NodeLen> id;//prameter to template is n-1
    vector<GraphNode*> neighbours;
public:
    GraphNode(bitset<NodeLen> id):id(id){};
    void AddNeighbour(GraphNode* GrNd){
        neighbours.push_back(GrNd);
    };
};

template <ssize_t SubSeqLen>
class DeBrujinGraph {
    vector<GraphNode <SubSeqLen-1> > nodes;
    void ConnectNodes() {
        for (unsigned long i = 0; i < pow (2, SubSeqLen-1) ; ++i) {
            unsigned long neighbour0Id= (i<<1);
            unsigned long neighbour1Id= (i<<1) + 1;
            GraphNode<SubSeqLen-1>* neighbour0 = nodes[neighbour0Id];
            GraphNode<SubSeqLen-1>* neighbour1 = nodes[neighbour1Id];
            nodes[i].AddNeighbour(neighbour0);
            nodes[i].AddNeighbour(neighbour1);
        }
    };

public:
    DeBrujinGraph(){
        for (unsigned long i = 0; i < pow (2, SubSeqLen-1) ; ++i) {
            bitset<SubSeqLen-1> IdBits(i);
//            GraphNode<SubSeqLen-1>N(IdBits)
            nodes.push_back(&GraphNode<SubSeqLen-1>(IdBits));
        }
        ConnectNodes();
    };
};


#endif //DEBROINPROJECT_DEBRUJINGRAPH_H
