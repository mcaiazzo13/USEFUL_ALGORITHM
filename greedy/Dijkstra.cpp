#include <iostream>
#include <iterator> // need for Dijkstra
#include <vector>
#include <queue> // need for Dijkstra
class Grafo{
private:
	vector<Nodo *> nodi;
	int vertici;
public:
	Grafo(int vertici,int wormhole);
	void setCosto(int costo);
	void insertNodo(Nodo *nodo);
	Nodo* getNodo(int n);
	int Dijkstra(Nodo* start,Nodo* end);
	~Grafo(){;}
};
// ------------------------------------ IMPLEMENTATION
// costruttore
Grafo::Grafo(int vertici,int wormhole){
	this->vertici = vertici;
	this->wormhole = wormhole;
}
// set costo
void Grafo::setCosto(int costo){
	this->costo = costo;
}
// aggiunge nodo
void Grafo::insertNodo(Nodo *nodo){
	this->nodi.push_back(nodo);
}
// get nodo
Nodo* Grafo::getNodo(int n){
	return this->nodi.at(n);
}
// Dijkstra
int Grafo::viaggia(Nodo *start,Nodo *end){
	// valore Nodo | chiave distanza
	priority_queue<pair <Nodo *,int> > coda;
	vector<int> dist;
	int i;
	for(i=0;i<this->vertici+1;i++){
		dist.push_back(99);
	}
	coda.push(make_pair(start,0));
	dist.at(start->getInfo()) = 0;
	
	Nodo *u;
	Nodo *v;
	int w = 0;
	while(!coda.empty()){
		u = coda.top().first; // take the head node
		coda.pop(); // pop the head node
		// now go through the ADJ'u with iterator
		list<pair<Nodo *,int> >::iterator itr;
		for(itr = u->getAdjBegin();itr != u->getAdjEnd();itr++){
			v = (*itr).first; // node v
			w = (*itr).second; // v weight
			// relax node
			if(dist.at(v->getInfo()) > dist.at(u->getInfo())+w){
				dist.at(v->getInfo()) = dist.at(u->getInfo())+w;
				v->setP(u);
				coda.push(make_pair(v,dist.at(v->getInfo())));
			}
		}
	}
	return dist.at(end->getInfo());
}
};
