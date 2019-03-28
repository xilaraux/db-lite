FROM ubuntu:18.04

WORKDIR /db-lite

COPY . /db-lite

RUN \
	apt-get update && \
	apt-get install -y && \
	apt-get install g++ -y && \
	apt-get install make -y && \
	apt-get install ruby -y && \
	apt-get install wget -y && \
	apt-get install vim -y && \
	apt-get install unzip -y && \
	gem install rspec

CMD ["/bin/bash"]

