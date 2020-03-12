#include <iostream>
#include <iterator> // dijkstra
#include <vector>
#include <queue> // dijkstra
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
// ------------------------------------ IMPLEMENTAZIONE
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
		u = coda.top().first; // prendo il nodo in testa
		coda.pop(); // estraggo il nodo
		// ora devo scorrere tutta la lista di ADJ di u
		list<pair<Nodo *,int> >::iterator itr;
		for(itr = u->getAdjBegin();itr != u->getAdjEnd();itr++){
			v = (*itr).first; // nodo v
			w = (*itr).second; // peso dell'arco di v
			// relax
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
