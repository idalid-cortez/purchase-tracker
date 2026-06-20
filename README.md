# purchase-tracker
High-performance C++ purchase tracker leveraging the STL std::map for efficient lookups. Features automated file processing, custom exception handling, and a type-safe data architecture to ensure data integrity and system scalability.

```mermaid
classDiagram
    class GroceryException {
        +GroceryException(message: string)
    }

    class Product {
        -name: string
        -purchaseCount: int
        +Product(name: string, count: int)
        +getName(): string
        +getCount(): int
        +incrementCount(): void
    }

    class PurchaseTracker {
        -productMap: map<string, Product>
        +processFile(filename: string)
        +saveBackup(filename: string)
        +searchFor(name: string): optional~Product~
        +printHistogram()
    }
```

    std_runtime_error <|-- GroceryException : inheritance
    PurchaseTracker o-- Product : composition
