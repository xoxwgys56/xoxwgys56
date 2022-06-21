# Auth

## CSRF Failed

```json
{
    "detail": "CSRF Failed: CSRF token missing or incorrect."
}
```

client generate *csrf token*.  
and set `X-CSRFToken` value inside of *header*.  

or first time user login, server send its *csrf token* then user store its data inside of sessionStorage.

---

### read more about CSRF

- [csrf-failed-csrf-token-missing-or-incorrect](https://stackoverflow.com/questions/26639169/csrf-failed-csrf-token-missing-or-incorrect)
- [drf session authentication](https://www.django-rest-framework.org/api-guide/authentication/#sessionauthentication)