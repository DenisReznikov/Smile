FROM ubuntu

RUN  apt-get update && apt-get install && -y libglew-dev libglfw3-dev && apt install qt5-default && apt-get install make && apt install git
RUN  git clone --depth=50 --branch=master https://github.com/DenisReznikov/Smile.git DenisReznikov/Smile
RUN  cd DenisReznikov/Smile/Smile
RUN  qmake
RUN  make
