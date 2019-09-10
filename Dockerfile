FROM ubuntu

RUN  apt-get update
RUN  apt-get install -y libglew-dev libglfw3-dev 
RUN  apt install qt5-default 
RUN  apt-get install make 
RUN  apt install git
RUN  git clone --depth=50 --branch=master https://github.com/DenisReznikov/Smile.git DenisReznikov/Smile
RUN  cd DenisReznikov/Smile/Smile
RUN  qmake
RUN  make
