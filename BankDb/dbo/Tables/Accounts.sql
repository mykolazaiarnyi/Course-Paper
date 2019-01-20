CREATE TABLE [dbo].[Accounts] (
    [Number] BIGINT     NOT NULL,
    [Money]  SMALLMONEY NOT NULL,
    [pin]    SMALLINT   NOT NULL,
    UNIQUE NONCLUSTERED ([Number] ASC)
);

