# CRSF

> Cross-Site Request Forgery
>
> 사이트 간 요청 위조

## TL;DR

### About CSRF Token

- who create?
  - client
- who validate?
  - server

> the only thing that counts is where it goes _to_.

more read about this.  

- [how-to-pass-csrf-token-from-server-to-client](https://stackoverflow.com/questions/50732159/how-to-pass-csrf-token-from-server-to-client)

---

## Prerequisites

아래의 조건을 만족하는 상태에서 *CSRF* 공격이 가능하다.

- 위조 요청을 전송하는 서비스(웹서비스)에 희생자(사용자)가 로그인한 상태
- 희생자(사용자)가 공격자(해커)가 만든 피싱 사이트(의도한 url)에 접속

## How to attack

나무위키 토론 주소는 이전에 아래같은 형식이었다.

```url
http://namu.wiki/topic/{{topic-id}}
```

이 패턴을 이용해서 일반적인 방법으로 접근할 수 없는 페이지를 열 수 있다. 예를 들어서

```url
http://namu.wiki/topic/admin-only
```

혹은 개발용으로 사용되지만, 사용자들에게 공개되지 않은 샘플 페이지 등을 찾아내는 행위가 가능하다.

이러한 형태로 취약한 *url*을 찾아서, 사용자를 로그아웃하게 만들거나 공개된 게시판 혹은 메일을 이용해 사용자가 해당 링크를 열게 만든다. 

> 이 경우 공격자는 해당 링크를 연 클라이언트가 될 것 이다.
>
> 혹은 이미 자신은 해당 웹페이지에 로그인해서 세션을 갖고 있기 때문에 자신의 세션 정보를 이용해 인증된 다음, 자신의 개인정보를 공격자가 의도한대로 변경할 수도 있을 것이다.

### Example

만약 어떤 사이트의 사용자 개인 비밀번호를 변경하는 주소 패턴이 아래와 같다고 하자.

```url
abc.com/user.do?cmd=user_passwd_change&user=admin&newPwd=1234
```

위의 링크로 접속한 사용자는 자신의 비밀번호를 "1234"로 바꾸게 될 것이다. (관리자에게 보내서 일반 계정을 관리자 계정으로 바꿀 수도 있다)

### `<img />`

`img` 태그도 **GET** 요청을 보내기 때문에 `img` 태그를 이용할 수도 있다.

### logout

나무위키의 경우 아래의 링크를 열게하면 사용자를 로그아웃하게 만들 수 있다. (이는 대부분 사이트의 문제이기도 하다)

```url
https://namu.wiki/member/logout
```

## How to defense

일반적으로 **GET** 요청이 아닌 **POST**, **PUT**, **DELETE** 요청에 방어를 적용합니다. (일반적으로, **GET** 요청은 데이터 변경이 일어나지 않기 때문에)

### Referer validation

*request*의 *referrer*를 확인하여, (요청한 *request*의) domain이 일치하는지 검증하는 방법.

#### Weakness of Referrer validation

- XSS(Cross-site scripting) vulnerability 있는 경우 취약하다
- Paros, Zap, fiddler 같은 프로그램으로 조작이 가능하다.

### CSRF Token

아래와 같이 토큰을 발급해서 사용자에게 갖고 있게 한 다음, 토큰값이 일치하는 비교해서 일치하지 않는 경우 요청을 거부하는 방법.

```js
session.setAttribute("CSRF_TOKEN", UUID.randomUUID().toString());
```

하지만 이 방법도 같은 도메인 내에 *XSS* 취약점이 있다면, *CSRF* 공격에 취약하다.

### CAPTCHA

*CAPTCHA*를 띄우는 방법도 있다.

## Read more about CSRF

- [CSRF-공격이란-그리고-CSRF-방어-방법](https://itstory.tk/entry/CSRF-%EA%B3%B5%EA%B2%A9%EC%9D%B4%EB%9E%80-%EA%B7%B8%EB%A6%AC%EA%B3%A0-CSRF-%EB%B0%A9%EC%96%B4-%EB%B0%A9%EB%B2%95)
- [나무위키 CSRF](https://namu.wiki/w/CSRF)
- [how-to-pass-csrf-token-from-server-to-client](https://stackoverflow.com/questions/50732159/how-to-pass-csrf-token-from-server-to-client)