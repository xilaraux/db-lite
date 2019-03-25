FROM ubuntu:18.04

COPY . /db-lite

RUN \
	apt-get update && \
	apt-get install -y && \
	apt-get install g++ -y && \
	apt-get install ruby -y && \
	apt-get install unzip -y && \
	gem install rspec

CMD ["/bin/bash"]

