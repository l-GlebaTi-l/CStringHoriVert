class CStringVert : public CString {
public:
    CStringVert(char *str) : CString(str){}
    int output(){   //  const char *FileName
        FILE *file = fopen(filename, "w");
        int i = 0;
        while(data[i] != '\0'){
            while(data[i] != ' ' && data[i] != '\0'){
                fprintf(file, "%c", data[i]);
                i++;
            }
            if(data[i] == '\0')
                break;
            fprintf(file, "\n");
            i++;
        }
        fclose(file);
        return 0;
    }
};

class FactoryCStringVert : public CFabricData{
public:
    CString* Create(char *str){
//        cout << "Vert!" << endl;
        return new CStringVert(str);
    }
};
