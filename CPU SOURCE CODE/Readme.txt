CPU BenchMark

•    Open Terminal
•    Connect EC2 using ssh -i "biya812.pem" ec2-user@ec2-52-91-94-113.compute-1.amazonaws.com
•    To transfer C file to EC2 use command scp -i /home/biya/biya812.pem /home/biya/cpu.c ec2-user@54.85.180.114:/home/ec2-user/PA1 in local terminal.
•    For compiling C file in Linux, compiler must be installed using  sudo yum group install ”Development Tools”
•    Set folder where the file is located.
•    Then run the command gcc cpu.c -lpthread
              gcc command used for compiling the file and –lpthread for thread execution.
•    Once, code gets compiled successfully then for execution of the program use ./a.out command.
