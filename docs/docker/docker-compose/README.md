# Docker compose

## execute command

```shell
docker-compose exec <service-name> <command>
```

example of *run django shell*

```shell
docker-compose exec web-service python3 manage.py shell
```

## use host network

variable `${LOCAL_IP}` read from  `.env` file

```docker
    extra_hosts:
      - localhost:${LOCAL_IP}
    env_file:
      - .env
```

### Read more about network-host

- winstonkotzan.com [connecting-to-external-postgres-database-with-docker](https://winstonkotzan.com/blog/2017/06/01/connecting-to-external-postgres-database-with-docker.html)
- [how-to-connect-locally-hosted-mysql-database-with-the-docker-container](https://stackoverflow.com/questions/44543842/how-to-connect-locally-hosted-mysql-database-with-the-docker-container)