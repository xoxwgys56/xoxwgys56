# GraphQL

## mutation

If queries are the GraphQL equivalent to `GET` calls in REST, then mutations represent the state-changing methods in REST (like `DELETE`, `PUT`, `PATCH`, etc).

```gql
mutation AddNewPet($name: String!, $petType: PetType) {
  addPet(name: $name, petType: $petType) {
    id
    name
    petType
  }
}
```

read more about [mutation-vs-query-when-to-use-graphql-mutation](https://www.apollographql.com/blog/graphql/basics/mutation-vs-query-when-to-use-graphql-mutation)

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

## Argument

### nullable

Arguments in GraphQL are nullable (i.e. optional) by **default**.

or in *resolver*, you can add parameter like below:

```ts
@Query((returns) => [Recipe])
async fetchRequest(
  @Arg('param', { nullable: true }) param: string
) {
  // some of codes ...
}
```

read more about [graphql-optional-query-arguments](https://stackoverflow.com/questions/64436979/graphql-optional-query-arguments)
