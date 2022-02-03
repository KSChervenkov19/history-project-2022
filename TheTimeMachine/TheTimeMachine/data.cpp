#include "data.h"

void data::createBaseNodes()
{
	/*
	NODE* temp = new NODE;
	temp->data = n;
	temp->next = NULL;

	if (head == NULL)
	{
		head = temp;
		tail = temp;
	}

	else
	{
		tail->next = temp;
		tail = tail->next;
	}
	*/

	NODE* node1 = new NODE;
	NODE* node2 = new NODE;
	NODE* node3 = new NODE;
	NODE* node4 = new NODE;
	NODE* node5 = new NODE;
	NODE* node6 = new NODE;
	NODE* node7 = new NODE;
	NODE* node8 = new NODE;
	NODE* node9 = new NODE;
	NODE* node10 = new NODE;
	NODE* node11 = new NODE;
	NODE* node12 = new NODE;
	NODE* node13 = new NODE;
	NODE* node14 = new NODE;
	NODE* node15 = new NODE;
	NODE* node16 = new NODE;
	NODE* node17 = new NODE;
	NODE* node18 = new NODE;
	NODE* node19 = new NODE;
	NODE* node20 = new NODE;
	NODE* node21 = new NODE;

	node1->id = 1;
	node1->name = "Battle of Ongal";
	node1->year = 680;
	node1->outcome = true;
	node1->description = "Bulgaria (with khan Asparuh as leader) against the Byzantine Empire";
	node1->goal = "Establishing  territory ownership";
	node1->area = "Lesser Scythia";
	node1->next = node2;

	node2->id = 2;
	node2->name = "Battle of Anchialus";
	node2->year = 708;
	node2->outcome = true;
	node2->description = "Bulgaria (with khan Tervel as leader) against the Byzantine Empire";
	node2->goal = "Bulgaria wishes to aid Justinian II to retake his throne.";
	node2->area = "Lands around Anchialus";
	node2->next = node3;

	node3->id = 3;
	node3->name = "Battle of Anchialus";
	node3->year = 708;
	node3->outcome = true;
	node3->description = "Bulgaria (with khan Tervel as leader) against the Byzantine Empire";
	node3->goal = "Bulgaria wishes to aid Justinian II to retake his throne.";
	node3->area = "Lands around Anchialus";
	node3->next = node3;
}