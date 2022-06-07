# Logging

## log level

source: [python logging](https://docs.python.org/ko/3.9/howto/logging.html#when-to-use-logging)

- `DEBUG`
  - 상세한 정보. 보통 문제를 진단할 때만 필요합니다.
- `INFO`
  - 예상대로 작동하는지에 대한 확인.
  - 예를 들어, "server succeed initialized"
- `WARNING`
  - 예상치 못한 일이 발생했거나 가까운 미래에 발생할 문제(예를 들어 〈디스크 공간 부족〉)에 대한 표시. 소프트웨어는 여전히 예상대로 작동합니다.
- `ERROR`
  - 더욱 심각한 문제로 인해, 소프트웨어가 일부 기능을 수행하지 못했습니다.
- `CRITICAL`
  - 심각한 에러. 프로그램 자체가 계속 실행되지 않을 수 있음을 나타냅니다.

`DEBUG`로그는 종종 코멘트의 역할을 하는 경우도 있습니다.  
이를 통해, 평소에는 프로그램 로깅 수준을 `INFO`에 두어 `DEBUG` 로그가 출력되지 않게 하다가, 문제가 발생한 경우 로그 레벨을 `DEBUG`로 변경하여 자세한 로그를 확인하는 방법도 있습니다.

## How to logging

- 명령행 스크립트 또는 프로그램의 일반적인 사용을 위한 콘솔 출력 표시
  - [print()](https://docs.python.org/ko/3.11/library/functions.html#print)
- 프로그램의 정상 작동 중에 발생하는 이벤트 보고 (가령 상태 모니터링이나 결함 조사)
  - [logging.info()](https://docs.python.org/ko/3.11/library/logging.html#logging.info) (또는 진단 목적의 아주 자세한 출력의 경우 [logging.debug()](https://docs.python.org/ko/3.11/library/logging.html#logging.debug))
- 특정 실행시간 이벤트와 관련하여 경고를 발행
  - 라이브러리 코드에서 [warnings.warn()](https://docs.python.org/ko/3.11/library/warnings.html#warnings.warn)
    - 문제를 피할 수 있고 경고를 제거하기 위해 클라이언트 응용 프로그램이 수정되어야 하는 경우
  - [logging.warning()](https://docs.python.org/ko/3.11/library/logging.html#logging.warning)
    - 클라이언트 응용 프로그램이 할 수 있는 일이 없는 상황이지만 이벤트를 계속 주목해야 하는 경우
- 특정 실행시간 이벤트와 관련하여 에러를 보고
  - 예외를 일으킵니다
- 예외를 발생시키지 않고 에러의 억제를 보고 (가령 장기 실행 서버 프로세스의 에러 처리기)
  - 구체적인 에러와 응용 프로그램 영역에 적절한 [logging.error()](https://docs.python.org/ko/3.11/library/logging.html#logging.error), [logging.exception()](https://docs.python.org/ko/3.11/library/logging.html#logging.exception), [logging.critical()](https://docs.python.org/ko/3.11/library/logging.html#logging.critical)

### read more about How to

- python logging doc: [when-to-use-logging](https://docs.python.org/ko/3.11/howto/logging.html#when-to-use-logging)
- [hwangheek.github.io](https://hwangheek.github.io/2019/python-logging/)

---

## Read more

- [파이썬 로깅의 모든것](https://hamait.tistory.com/880)
