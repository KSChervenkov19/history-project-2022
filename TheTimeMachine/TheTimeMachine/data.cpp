#include "data.h"

void data::createBaseNodes()
{
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


	node1->id = 1;
	node1->name = "Battle of Ongal";
	node1->year = 680;
	node1->outcome = "The battle was won by Bulgaria";
	node1->description = "Bulgaria (with khan Asparuh as leader) against the Byzantine Empire";
	node1->reason = "Establishing  territory ownership";
	node1->area = "Lesser Scythia";
	node1->next = node2;

	node2->id = 2;
	node2->name = "Battle of Anchialus";
	node2->year = 708;
	node2->outcome = "The battle was won by Bulgaria";
	node2->description = "Bulgaria (with khan Tervel as leader) against the Byzantine Empire";
	node2->reason = "Bulgaria wishes to aid Justinian II to retake his throne";
	node2->area = "Lands around Anchialus";
	node2->next = node3;

	node3->id = 3;
	node3->name = "Battle of Varbitsa Pass";
	node3->year = 811;
	node3->outcome = "The battle was won by Bulgaria";
	node3->description = "Bulgaria (with khan Krum as leader) against the Byzantine Empire";
	node3->reason = "Byzantine Empire declares war to expand it's boundaries";
	node3->area = "Varbitsa Pass";
	node3->next = node4;

	node4->id = 4;
	node4->name = "Siege of Adrianople";
	node4->year = 813;
	node4->outcome = "The battle was won by Bulgaria";
	node4->description = "Bulgaria (with khan Krum as leader) against the Byzantine Empire";
	node4->reason = "Byzantine Empire declares war to expand it's boundaries";
	node4->area = "Adrianople, present Edirne, Turkey";
	node4->next = node5;

	node5->id = 5;
	node5->name = "Battle of Versinikia";
	node5->year = 814;
	node5->outcome = "The battle was won by Bulgaria";
	node5->description = "Bulgaria (with khan Krum as leader) against the Byzantine Empire";
	node5->reason = "Byzantine Empire declares war to expand it's boundaries";
	node5->area = "Versinikia, present Elhovo";
	node5->next = node6;

	node6->id = 6;
	node6->name = "Battle of Pegae";
	node6->year = 920;
	node6->outcome = "The battle was won by Bulgaria";
	node6->description = "Bulgaria (with tsar Simeon I as leader) against the Byzantine Empire";
	node6->reason = "Tsar Simeon wants to expand his influence over the Byzantine Empire";
	node6->area = "Pegae, Byzantine Empire";
	node6->next = node7;

	node7->id = 7;
	node7->name = "Battle of the Gates of Trajan";
	node7->year = 986;
	node7->outcome = "The battle was won by Bulgaria";
	node7->description = "Bulgaria (with tsar Samuel and Aron as leaders) against the Byzantine Empire";
	node7->reason = "Tsar Samuel sees an opportunity to expand his territories because of the weak state of the Byzantine empire";
	node7->area = "The mountain pass Trajan's Gate (Trayanovi vrata), Bulgaria";
	node7->next = node8;

	node8->id = 8;
	node8->name = "Battle of Thessalonica";
	node8->year = 995;
	node8->outcome = "The battle was won by Bulgaria";
	node8->description = "Bulgaria (with tsar Samuel as leader) against the Byzantine Empire";
	node8->reason = "Samuel sees the outcome of his victory at Gates of Trajan and continues on south";
	node8->area = "Thessalonica, Byzantine Empire";
	node8->next = node9;

	node9->id = 9;
	node9->name = "Battle of Skopje";
	node9->year = 1003;
	node9->outcome = "The battle was won by the Byzantine Empire";
	node9->description = "Bulgaria (with tsar Samuel as leader) against the Byzantine Empire";
	node9->reason = "The successful progress of Basil II's campaign against Bulgaria";
	node9->area = "Skopje, present North Macedonia";
	node9->next = node10;

	node10->id = 10;
	node10->name = "Battle of Strumica";
	node10->year = 1014;
	node10->outcome = "The battle was won by Bulgaria";
	node10->description = "Bulgaria (with tsar Samuel as leader) against the Byzantine Empire";
	node10->reason = "Recovering territories and blocking the Byzantine empire";
	node10->area = "Between Belasica and Plavush, present-day North Macedonia";
	node10->next = node11;

	node11->id = 11;
	node11->name = "Battle of Kleidion";
	node11->year = 1014;
	node11->outcome = "The battle was won by the Byzantine Empire";
	node11->description = "Bulgaria (with tsar Samuel as leader) against the Byzantine Empire";
	node11->reason = "To stop the Byzantine Empire from attacking Bulgaria";
	node11->area = "Between Belasica and Ograzden, near present-day village Klyuch in Bulgaria";
	node11->next = node12;

	node12->id = 12;
	node12->name = "Battle of Tryavna";
	node12->year = 1190;
	node12->outcome = "The battle was won by Bulgaria";
	node12->description = "Bulgaria (with tsar Ivan Asen I and tsar Peter I Asen as leaders) against the Byzantine Empire";
	node12->reason = "Tsar Ivan Asen I used the third crusade as an advantage to recover lost territories to Bulgaria";
	node12->area = "Tryavna, Bulgaria";
	node12->next = node13;

	node13->id = 13;
	node13->name = "Battle of Klokotnitsa";
	node13->year = 1230;
	node13->outcome = "The battle was won by Bulgaria";
	node13->description = "Bulgaria (with tsar Ivan Asen II as leader) against the Epirus despotism";
	node13->reason = "To cease Teodor Komnin and his plan to prevent tsar Ivan Asen II of increasing Bulgaria's influence";
	node13->area = "Between the river Klokotnitsa and the village Klokotnitsa";
	node13->next = node14;

	node14->id = 14;
	node14->name = "Battle of Skafida";
	node14->year = 1304;
	node14->outcome = "The battle was won by Bulgaria";
	node14->description = "Bulgaria (with tsar Teodor Svetoslav as leader) against the Byzantine Empire";
	node14->reason = "Recover territories and take revenge on the Byzantine empire";
	node14->area = "Near Burgas, Bulgaria";
	node14->next = node15;

	node15->id = 15;
	node15->name = "Battle of Rusokastro";
	node15->year = 1332;
	node15->outcome = "The battle was won by Bulgaria";
	node15->description = "Bulgaria (with tsar Ivan Aleksandar as leader) against the Byzantine Empire";
	node15->reason = "An attempt to stop the invasion of the Byzantine Empire, which grows into an attack against them";
	node15->area = "Near Rusokastro";
	node15->next = node16;

	node16->id = 16;
	node16->name = "April Uprising";
	node16->year = 1876;
	node16->outcome = "The battle was won by the Ottoman Empire";
	node16->description = "Insurgent activists of BRCC (Georgi Benkovski, Stoyan Zaimov, Panayot Volov, Ilarion Dragostinov, Stefan Stambolov) against the Ottoman Empire";
	node16->reason = "An attempt to get the attention of Europe and proclaim that there is still a nation fighting for it's survival in the Empire";
	node16->area = "Tarnovo, Sliven, Vratsa, Plovdiv (and the nearby villages)";
	node16->next = node17;

	node17->id = 17;
	node17->name = "Battle of Shipka Pass";
	node17->year = 1877;
	node17->outcome = true;
	node17->description = "The battle went on for three days (August 9-11) between Russian troops helped by Bulgarian volunteers (Gen. Stoletov as leader) against the Ottoman Empire";
	node17->reason = "Holding the line until the arrival of reinforcements, so that they don't lose their progress in the war";
	node17->area = "Shipka Pass";
	node17->next = node18;

	node18->id = 18;
	node18->name = "Serbo-Bulgarian War";
	node18->year = 1885;
	node18->outcome = "The battle was won by Bulgaria";
	node18->description = "Bulgaria against Serbia";
	node18->reason = "Serbia's dissatisfaction with the unification between the Kingdom of Bulgaria and Eastern Rumelia resulted to Serbia declaring a war";
	node18->area = "Nish (present-day Serbia), Vidin, Pirot, Dragoman, Tsaribrod (Dimitrovgrad), Slivnitsa";
	node18->next = node19;

	node19->id = 19;
	node19->name = "Balkan War";
	node19->year = 1912;
	node19->outcome = "The battle was won by Bulgaria";
	node19->description = "Balkan Union (Bulgaria, Serbia, Greece, Montenegro) against the Ottoman Empire";
	node19->reason = "Expanding to new territories and restoration of old ones (unsuccessful)";
	node19->area = "In many cities and terriroies in the Balkans";
	node19->next = node20;

	node20->id = 20;
	node20->name = "World War 1";
	node20->year = 1914;
	node20->outcome = "The battle was won by the Entente";
	node20->description = "Central Powers (Germany, Italy, Austria-Hungary) against the Entente";
	node20->reason = "Bulgaria joined the war on 14th October 1915 on the side of the Central Powers, because they were promised territorial compensation";
	node20->area = "Most of Bulgaria's military campaigns during World War I took place around the border of the country";
	node20->next = NULL;

	while (node1 != NULL)
	{
		events.push_back(node1);
		node1 = node1->next;
	}
}

void data::displayNames()
{
	for (NODE* event : events)
	{
		std::cout << "  Name: " << event->name << "\n";
	}
}

void data::findEventByYear(int year)
{
	closestYear = INT_MAX;
	for (NODE* event : events)
	{
		if (year == event->year)
		{
			std::cout << "  Name: " <<event->name << "\n";
			std::cout << "  Year: " << event->year << "\n";
			std::cout << "  Description: " << event->description << "\n";
			std::cout << "  Reason: " << event->reason << "\n";
			std::cout << "  Won: " << event->outcome << "\n";
			std::cout << "  Area: " << event->area << "\n";
			found = true;
		}
		else
		{
			if (year <= closestYear)
			{
				closestYear = year;
			}
		}
	}
	if (!found)
	{
		std::cout << "% Unknown year. Closest year: "<< closestYear << "\n";
	}
}

void data::findEventByName(std::string name)
{
	for (NODE* event : events)
	{
		if (name == event->name)
		{
			std::cout << "  Name: " << event->name << "\n";
			std::cout << "  Year: " << event->year << "\n";
			std::cout << "  Description: " << event->description << "\n";
			std::cout << "  Reason: " << event->reason << "\n";
			std::cout << "  Won: " << event->outcome << "\n";
			std::cout << "  Area: " << event->area << "\n";
		}
	}
	if (!found)
	{
		std::cout << "% Unknown name. Press \"?\" to see all available names" << "\n";
	}
}

void data::findEventByOutcome(std::string outcome)
{
	std::cout << "eysae";
}