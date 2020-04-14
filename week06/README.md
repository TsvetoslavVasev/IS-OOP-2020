# File Streams

## Type of streams for files
|Type|Description|
|----|-----------|
|ofstream|This data type represents the output file stream and is used to create files and to write information to files.|
|ifstream|This data type represents the input file stream and is used to read information from files.|
|fstream|This data type represents the file stream generally, and has the capabilities of both ofstream and ifstream which means it can create files, write information to files, and read information from files.|

## How you can open a file

##### Example

###### Open a file for reading:
```
ifstream infile;
infile.open("file.dat", ios::in);
```
###### Open a file for writing:
```
ofstream outfile;
outfile.open("file.dat", ios::out | ios::trunc );
```
###### Open a file both for reading and writing:
```
fstream  afile;
afile.open("file.dat", ios::out | ios::in );
```
### Type of flags
|Flag|Description|
|----|-----------|
|ios::app|Append mode. All output to that file to be appended to the end.|
|ios::ate|Open a file for output and move the read/write control to the end of the file.|
|ios::in|Open a file for reading.|
|ios::out|Open a file for writing.|
|ios::trunc|If the file already exists, its contents will be truncated before opening the file.|

### Closing a File
```
ifstream infile;
infile.open("file.dat", ios::in);
.... //Some code 
 infile.close();
```
