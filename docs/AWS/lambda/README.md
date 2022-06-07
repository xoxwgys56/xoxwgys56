# lambda

## logging

in python

source: [aws-람다-로그-잘-남기고-추적하기](https://asleea88.medium.com/aws-람다-로그-잘-남기고-추적하기-aws-lambda-logging-f097dddbbc52)

```python
import logging


def handler(event, context):
    logger = logging.getLogger(context.aws_request_id)
    logger.setLevel(logging.DEBUG)
    logger.info('logger message')
```

람다는 `context` 내에 로거 이름이 저장되어 있다.  
그 외에 보유한 속성 값은 아래에 설명되어 있다.
로그와 무관하다고 생각되는 속성들은 제외하였다.

### context method

- `get_remaining_time_in_millis` – 실행 시간이 초과되기 전에 남은 시간(밀리초)을 반환합니다.

### context attribute

- `aws_request_id` – 호출 요청의 식별자
- `log_group_name` – 함수에 대한 로그 그룹
- `log_stream_name` – 함수 인스턴스에 대한 로그 스트림
- `identity` – (모바일 앱) 요청을 승인한 Amazon Cognito 자격 증명에 대한 정보
  - `cognito_identity_id` – 인증된 Amazon Cognito 자격 증명
  - `cognito_identity_pool_id` – 호출에 대한 권한을 부여한 Amazon Cognito ID 풀

---

## Read more

- AWS lambda [python-context](https://docs.aws.amazon.com/ko_kr/lambda/latest/dg/python-context.html)
