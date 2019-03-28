docker build --tag=db-lite:v1 . && \
docker run -d --name lolipop db-lite:v1 /bin/sh && \
docker container exec -it lolipop /bin/sh

