# GraphQL

## TypeGraphQL

### Resolver

class based resolver

```ts
@Resolver()
class RecipeResolver {
  private recipesCollection: Recipe[] = [];

  @Query((returns) => [Recipe])
  async recipes() {
    return await this.recipesCollection;
  }
}
```

read more about [ts resolver](https://typegraphql.com/docs/resolvers.html)
