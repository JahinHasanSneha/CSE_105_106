#include <iostream>
#include <fstream>
#include <string>
#include "listBST.hpp"
using namespace std;
void printA(BST<string, int> *items)
{
    cout << "BST (In-order): ";
    items->print('I');
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cerr << "Usage: filename" << "\n";
        return 1;
    }
    ifstream in_file(argv[1]);
    if (!in_file)
    {
        cerr << "Unable to open file\n";
        return 1;
    }

    // TODO: Declare data structures to track bid statistics for each item

    // You need to track: total bids, successful bids, rejected bids for each item
    // Hint: You may use additional BSTs or other data structures
    // Start your code here
    int index = 0;
    int MAX = 5000;
    string *array = new string[MAX];
    BST<string, int> *curHighestBid = new ListBST<string, int>();
    BST<string, int> *totalBids = new ListBST<string, int>();
    BST<string, int> *rejected = new ListBST<string, int>();
    BST<string, int> *accepted = new ListBST<string, int>();
    // bool ok=false;
    // for(int i=0;i<index;i++)
    // {
    //     if(array[i]==id)
    //     {
    //         ok=true;
    //         break;
    //     }
    // }

    // End your code here

    int n;
    in_file >> n;

    for (int i = 0; i < n; ++i)
    {
        string id;
        int st;
        in_file >> id >> st;

        // TODO: Implement the logic to read initial items and their starting bids
        // Initialize statistics tracking for each item
        // Start your code here
        curHighestBid->insert(id, st);
        totalBids->insert(id, 0);
        rejected->insert(id, 0);
        accepted->insert(id, 0);
        if (index < MAX)
        {
            array[index++] = id;
        }
        // End your code here
    }

    // TODO: Implement the logic to print the initial auction state
    // Start your code here
    cout << "Initial auction items:" << endl;
    printA(curHighestBid);
    cout << endl;
    // End your code here
    cout << "\nAuction starts!\n\n";
    cout << "==============================\n";

    string operation;
    while (in_file >> operation)
    {
        // TODO: Implement the logic to process operations (ADD, BID, CHECK, STATS, REPORT) and print auction state after each operation
        // For BID operations: update statistics (total bids, successful/rejected counts)
        // For STATS operations: display statistics for the specified item
        // For REPORT operations: display comprehensive auction statistics
        // For other operations: print auction state using in-order traversal
        // Start your code here
        if (operation == "BID")
        {
            string id;
            int bid;
            in_file >> id >> bid;
            if (!curHighestBid->find(id))
            {
                cout << "Bid of " << bid << " on " << id << " rejected " << endl;
                printA(curHighestBid);
            }
            else
            {
                int now = curHighestBid->get(id);
                totalBids->update(id, totalBids->get(id) + 1);
                if (bid > now)
                {
                    curHighestBid->update(id, bid);
                    accepted->update(id, accepted->get(id) + 1);
                    cout << "Bid of " << bid << " on " << id << " accepted. Current bid: " << bid << endl;
                }
                else
                {
                    rejected->update(id, rejected->get(id) + 1);
                    cout << "Bid of " << bid << " on " << id << " rejected. Current bid: " << now << endl;
                }
                printA(curHighestBid);
            }
        }
        else if (operation == "STATS")
        {
            string id;

            in_file >> id;
            cout << "Statistics for " << id << ":" << endl;
            cout << " Current highest bid: " << curHighestBid->get(id) << endl;
            cout << " Total bids placed: " << totalBids->get(id) << endl;
            cout << " Successful bids: " << accepted->get(id) << endl;
            cout << " Rejected bids: " << rejected->get(id) << endl;
        }
        else if (operation == "REPORT")
        {
            int allBids = 0, allAccepted = 0, allRejected = 0;
            int allItems = (int)curHighestBid->size();
            for (int i = 0; i < index; i++)
            {
                string id = array[i];
                allBids = allBids + totalBids->get(id);
                allAccepted = allAccepted + accepted->get(id);
                allRejected = allRejected + rejected->get(id);
            }
            for (int i = 0; i < index - 1; i++)
            {
                for (int j = i + 1; j < index; j++)
                {
                    if (array[i] > array[j])
                    {
                        string temp = array[i];
                        array[i] = array[j];
                        array[j] = temp;
                    }
                }
            }
            cout << "Auction Report: " << endl;
            cout << "Total items: " << allItems << endl;
            cout << "Total bids placed: " << allBids << endl;
            cout << "Total successful bids: " << allAccepted << endl;
            cout << "Total rejected bids: " << allRejected << endl;

            cout << endl;
            cout << "Item Statistics: " << endl;
            for (int i = 0; i < index; i++)
            {
                string id = array[i];
                cout << "  " << id << ": Current bid: " << curHighestBid->get(id) << ", Total bids: " << totalBids->get(id) << ", Successful: " << accepted->get(id) << ", Rejected: " << rejected->get(id) << endl;
            }
        }

        else if (operation == "CHECK")
        {
            string id;

            in_file >> id;
            if (!curHighestBid->find(id))
            {
                cout << "Item " << id << " not found" << endl;
            }
            else
            {
                cout << "Current bid for " << id << ": " << curHighestBid->get(id) << endl;
            }
            printA(curHighestBid);
        }
        else if (operation == "ADD")
        {
            string id;
            int st;
            in_file >> id >> st;
            if (curHighestBid->find(id))
            {
                int cur = curHighestBid->get(id);
                if (st > cur)
                {
                    curHighestBid->update(id, st);
                    cout << "Item " << id << " updated with starting bid " << st << endl;
                }
                else
                {
                    cout << "ADD rejected: item already exists" << endl;
                }
            }
            else
            {
                curHighestBid->insert(id, st);
                totalBids->insert(id, 0);
                rejected->insert(id, 0);
                accepted->insert(id, 0);
                if (index < MAX)
                {

                    array[index++] = id;
                }
                cout << "Item " << id << " added with starting bid " << st << endl;
                printA(curHighestBid);
            }
        }
        cout << "==============================\n";
        // End your code here
    }

    in_file.close();
    // TODO: Delete data structures you created
    // Start your code here
    delete curHighestBid;
    delete totalBids;
    delete rejected;
    delete accepted;
    delete[] array;
    // End your code here
    return 0;
}
