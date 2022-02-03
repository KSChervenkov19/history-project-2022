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
	node1->reason = "Establishing  territory ownership";
	node1->area = "Lesser Scythia";
	node1->next = node2;

	node2->id = 2;
	node2->name = "Battle of Anchialus";
	node2->year = 708;
	node2->outcome = true;
	node2->description = "Bulgaria (with khan Tervel as leader) against the Byzantine Empire";
	node2->reason = "Bulgaria wishes to aid Justinian II to retake his throne";
	node2->area = "Lands around Anchialus";
	node2->next = node3;

	node3->id = 3;
	node3->name = "Battle of Varbitsa Pass";
	node3->year = 811;
	node3->outcome = true;
	node3->description = "Bulgaria (with khan Krum as leader) against the Byzantine Empire";
	node3->reason = "Byzantine Empire declares war to expand it's boundaries";
	node3->area = "Varbitsa Pass";
	node3->next = node4;

	node4->id = 4;
	node4->name = "Siege of Adrianople";
	node4->year = 813;
	node4->outcome = true;
	node4->description = "Bulgaria (with khan Krum as leader) against the Byzantine Empire";
	node4->reason = "Byzantine Empire declares war to expand it's boundaries";
	node4->area = "Adrianople, present Edirne, Turkey";
	node4->next = node5;

	node5->id = 5;
	node5->name = "Battle of Versinikia";
	node5->year = 814;
	node5->outcome = true;
	node5->description = "Bulgaria (with khan Krum as leader) against the Byzantine Empire";
	node5->reason = "Byzantine Empire declares war to expand it's boundaries";
	node5->area = "Versinikia, present Elhovo";
	node5->next = node6;

	node6->id = 6;
	node6->name = "Battle of Pegae";
	node6->year = 920;
	node6->outcome = true;
	node6->description = "Bulgaria (with tsar Simeon I as leader) against the Byzantine Empire";
	node6->reason = "Tsar Simeon wants to expand his influence over the Byzantine Empire";
	node6->area = "Pegae, Byzantine Empire";
	node6->next = node7;

	node7->id = 7;
	node7->name = "Battle of the Gates of Trajan";
	node7->year = 986;
	node7->outcome = true;
	node7->description = "Bulgaria (with tsar Samuel and Aron as leaders) against the Byzantine Empire";
	node7->reason = "Tsar Samuel sees an opportunity to expand his territories because of the weak state of the Byzantine empire";
	node7->area = "The mountain pass Trajan's Gate (Trayanovi vrata), Bulgaria";
	node7->next = node8;

	node8->id = 8;
	node8->name = "Battle of Thessalonica";
	node8->year = 995;
	node8->outcome = true;
	node8->description = "Bulgaria (with tsar Samuel as leader) against the Byzantine Empire";
	node8->reason = "Samuel sees the outcome of his victory at Gates of Trajan and continues on south";
	node8->area = "Thessalonica, Byzantine Empire";
	node8->next = node9;

	node9->id = 9;
	node9->name = "Battle of Skopje";
	node9->year = 1003;
	node9->outcome = false;
	node9->description = "Bulgaria (with tsar Samuel as leader) against the Byzantine Empire";
	node9->reason = "The successful progress of Basil II's campaign against Bulgaria";
	node9->area = "Skopje, present North Macedonia";
	node9->next = node10;

	node10->id = 10;
	node10->name = "Battle of Strumica";
	node10->year = 1014;
	node10->outcome = true;
	node10->description = "Bulgaria (with tsar Samuel as leader) against the Byzantine Empire";
	node10->reason = "Recovering territories and blocking the Byzantine empire";
	node10->area = "Between Belasica and Plavush, present-day North Macedonia";
	node10->next = node11;
}