#include "Client.h"
#include <iostream>
#include <limits> 

static void showMenu( void )
{
    std::cout << ("\n\nChat menu\n");
    std::cout << ("===============\n");
    std::cout << ("(1) Connect\n");
    std::cout << ("(2) Disconnect\n");
    std::cout << ("(3) Send File\n");
    std::cout << ("(4) Request File <not implemented>\n");
    std::cout << ("(5) Delete File <not implemented>\n");
    std::cout << ("(q) Exit\n");

    std::cout << ("Choice : ");
}

int main (void)
{
    bool quit = false;
    bool connected = false;
    Client* client = new Client();

    while (!quit)
    {
        std::string message = "";
        char choice = '\0';
        showMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice)
        {
        case '1' : //connect
        {
            if (!connected)
            {
                client->InitialiseSocket("127.0.0.1");
                if (client >= 0)
                {
                    connected = true;
                    std::cout << "Connected with localhost" << std::endl;
                }                
            }
            else
            {
                std::cout << "Already connected. We don't have multiple personality disorder" << std::endl;
            }
            break;
        }           
        case '2' : //disconnect
        {
            if (client->Disconnect())
            {
                connected = false;
                std::cout << "Disconnected" << std::endl;
            }
            else
            {
                std::cout << "Unable to disconnect. But the program will close beause there is probably no connection anyway and if there is then it will be closed when this program closes so no biggy, we got you covered!" << std::endl;
            }
            
            break;
        }
        case '3' : //send file
        {
            std::string fileName;

            std::cout << "enter file name" << std::endl;
            std::cin >> fileName;
            //std::cin.ignore();
            std::cout << "filename: " << fileName << std::endl;
            int fileSize = client->GetFileSize(fileName);
            std::cout << "filesize: " << fileSize << std::endl;
            if (fileSize > 0)
            {
                if(client->RequestSave(fileSize))
                {
                    client->SendFile(fileName, fileSize);
                    std::cout << "File sent";
                }
            }
            else
            {
                std::cout << "something went wrong?" << std::endl;
            }
        }
            break;
        case '4' : //request file
        {
                //TODO
        }
            break;
        case '5' : //delete file
        {
                //TODO
            break;
        }
        case 'q' : //quit
        {
            quit = true;
            if (client->Disconnect())
            {
                connected = false;
                std::cout << "Disconnected" << std::endl;
            }
            else
            {
                std::cout << "Unable to disconnect. But the program will close beause there is probably no connection anyway and if there is then it will be closed when this program closes so no biggy, we got you covered!" << std::endl;
            }
            break;
        }
            
        default:
            std::cout << "\n\nI did not understand your choice (" << choice << ")" << std::endl;
            break;
        }
    }
    delete client;
    client = NULL;
    return 0;
}