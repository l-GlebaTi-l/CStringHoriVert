class CString { //  template <typename T>
protected:
    char* filename;
    char* data;
public:
    CString(char* Data){
        int i = 0;
        filename = new char[128];
        cout << "CString 1" << endl;
        while(Data[i] != '.'){
//            filename = (char*)realloc(filename, (i+2)*sizeof(char));
            filename[i] = Data[i];
            i++;
        }
//        cout << "CString 2" << endl;
        filename[i] = '.';
        i++;
        while(Data[i] != ' '){
            filename = (char*)realloc(filename, (i+2)*sizeof(char));
            filename[i] = Data[i];
            i++;
        }
        i++;
//        cout << "CString 3 = " << Data[i] << endl;
        filename[i] = '\0';

        cout << "try to add mem";
        char* tempdata = new char[256];
//        cout << "..." << endl;
//        tempdata = (char*)realloc(tempdata, 256*sizeof(char));
        cout << "successfully!" << endl;
        int n = 0;
        while(Data[i] != '\0'){
            if(n == 256){
                tempdata = (char*)realloc(tempdata, 1024*sizeof(char));
            }
            if(n > 1023){
                tempdata = (char*)realloc(tempdata, n*sizeof(char));
            }
            if(Data[i] == '\n' || Data[i] == '\r' || Data[i] == '\0'){
                tempdata[n] = '\0';
                n++;
                break;
            }
//            cout << " : " << Data[i] << endl;
            tempdata[n] = Data[i];
            n++;
            i++;
        }
        cout << "CString 4" << endl;
        tempdata[n] = '\0';
        tempdata = (char*)realloc(tempdata, (n+1)*sizeof(char));
        cout << "CString 5" << endl;
        data = tempdata;
        cout << "CString 6" << endl;
    }
    virtual int output() = 0;   //  const char *FileName    FILE *file = fopen(filename, "r");
    virtual ~CString(){
        delete[] data;
        delete[] filename;
    }
};
